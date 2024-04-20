#include "TsIntegerVectorFromScaleTimesIntegerVector.hh"

TsIntegerVectorFromScaleTimesIntegerVector::TsIntegerVectorFromScaleTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "iv");
}


TsIntegerVectorFromScaleTimesIntegerVector::~TsIntegerVectorFromScaleTimesIntegerVector()
{
}


G4String TsIntegerVectorFromScaleTimesIntegerVector::GetType()
{
	G4String type = "iv";
	return type;
}


G4int TsIntegerVectorFromScaleTimesIntegerVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4int* TsIntegerVectorFromScaleTimesIntegerVector::GetIntegerVector()
{
	fUsed = true;
	G4int* values = new G4int[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = fValue * EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsIntegerVectorFromScaleTimesIntegerVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
