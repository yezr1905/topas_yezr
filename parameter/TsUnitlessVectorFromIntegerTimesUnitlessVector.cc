#include "TsUnitlessVectorFromIntegerTimesUnitlessVector.hh"

TsUnitlessVectorFromIntegerTimesUnitlessVector::TsUnitlessVectorFromIntegerTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "uv");
}


TsUnitlessVectorFromIntegerTimesUnitlessVector::~TsUnitlessVectorFromIntegerTimesUnitlessVector()
{
}


G4String TsUnitlessVectorFromIntegerTimesUnitlessVector::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromIntegerTimesUnitlessVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter2);
}


G4double* TsUnitlessVectorFromIntegerTimesUnitlessVector::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateUnitlessVector(fNameOfOtherParameter2)[iValue];
	return values;
}


G4String TsUnitlessVectorFromIntegerTimesUnitlessVector::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
