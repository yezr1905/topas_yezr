#include "TsBooleanFromValue.hh"

TsBooleanFromValue::TsBooleanFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	fValue = ConvertToBoolean(value);
}


TsBooleanFromValue::~TsBooleanFromValue()
{
}


G4String TsBooleanFromValue::GetType()
{
	G4String type = "b";
	return type;
}


G4bool TsBooleanFromValue::GetBooleanValue()
{
	fUsed = true;
	return fValue;
}


G4String TsBooleanFromValue::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
