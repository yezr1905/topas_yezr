#include "TsDoubleVectorFromScaleTimesDoubleVector.hh"

TsDoubleVectorFromScaleTimesDoubleVector::TsDoubleVectorFromScaleTimesDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "dv");
}


TsDoubleVectorFromScaleTimesDoubleVector::~TsDoubleVectorFromScaleTimesDoubleVector()
{
}


void TsDoubleVectorFromScaleTimesDoubleVector::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleVectorFromScaleTimesDoubleVector::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromScaleTimesDoubleVector::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromScaleTimesDoubleVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4double* TsDoubleVectorFromScaleTimesDoubleVector::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = fValue * EvaluateDoubleVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsDoubleVectorFromScaleTimesDoubleVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	return output;
}
