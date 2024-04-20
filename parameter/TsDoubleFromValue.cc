#include "TsDoubleFromValue.hh"

TsDoubleFromValue::TsDoubleFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
									   const G4String& value, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	fValue = ConvertToDouble(value);

	CheckUnit(unit);
}


TsDoubleFromValue::~TsDoubleFromValue()
{
}


G4String TsDoubleFromValue::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromValue::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromValue::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit);
}


G4String TsDoubleFromValue::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	return output;
}
