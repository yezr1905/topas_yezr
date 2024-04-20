#include "TsUnitlessVectorFromScaleTimesUnitlessVector.hh"

TsUnitlessVectorFromScaleTimesUnitlessVector::TsUnitlessVectorFromScaleTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "uv");
}


TsUnitlessVectorFromScaleTimesUnitlessVector::~TsUnitlessVectorFromScaleTimesUnitlessVector()
{
}


G4String TsUnitlessVectorFromScaleTimesUnitlessVector::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromScaleTimesUnitlessVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4double* TsUnitlessVectorFromScaleTimesUnitlessVector::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = fValue * EvaluateUnitlessVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsUnitlessVectorFromScaleTimesUnitlessVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
