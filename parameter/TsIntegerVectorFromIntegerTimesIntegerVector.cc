#include "TsIntegerVectorFromIntegerTimesIntegerVector.hh"

TsIntegerVectorFromIntegerTimesIntegerVector::TsIntegerVectorFromIntegerTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "iv");
}


TsIntegerVectorFromIntegerTimesIntegerVector::~TsIntegerVectorFromIntegerTimesIntegerVector()
{
}


G4String TsIntegerVectorFromIntegerTimesIntegerVector::GetType()
{
	G4String type = "iv";
	return type;
}


G4int TsIntegerVectorFromIntegerTimesIntegerVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter2);
}


G4int* TsIntegerVectorFromIntegerTimesIntegerVector::GetIntegerVector()
{
	fUsed = true;
	G4int* values = new G4int[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateIntegerVector(fNameOfOtherParameter2)[iValue];
	return values;
}


G4String TsIntegerVectorFromIntegerTimesIntegerVector::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
