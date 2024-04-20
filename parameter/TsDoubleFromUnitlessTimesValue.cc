#include "TsDoubleFromUnitlessTimesValue.hh"

TsDoubleFromUnitlessTimesValue::TsDoubleFromUnitlessTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																 const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsDoubleFromUnitlessTimesValue::~TsDoubleFromUnitlessTimesValue()
{
}


G4String TsDoubleFromUnitlessTimesValue::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromUnitlessTimesValue::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromUnitlessTimesValue::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit) * EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromUnitlessTimesValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " * ";
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	return output;
}
