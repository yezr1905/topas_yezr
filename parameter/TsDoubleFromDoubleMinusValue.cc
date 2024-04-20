#include "TsDoubleFromDoubleMinusValue.hh"

TsDoubleFromDoubleMinusValue::TsDoubleFromDoubleMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														 const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromDoubleMinusValue::~TsDoubleFromDoubleMinusValue()
{
}


void TsDoubleFromDoubleMinusValue::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromDoubleMinusValue::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDoubleMinusValue::GetUnit()
{
	return fUnit;
}


G4double TsDoubleFromDoubleMinusValue::GetDoubleValue()
{
	fUsed = true;
	return EvaluateDoubleParameter(fNameOfOtherParameter) - fValue * fPm->GetUnitValue(fUnit);
}


G4String TsDoubleFromDoubleMinusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " - ";
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	return output;
}
