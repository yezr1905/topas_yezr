#include "TsIntegerFromValue.hh"

TsIntegerFromValue::TsIntegerFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	fValue = ConvertToInteger(value);
}


TsIntegerFromValue::~TsIntegerFromValue()
{
}


G4String TsIntegerFromValue::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromValue::GetIntegerValue()
{
	fUsed = true;
	return fValue;
}


G4String TsIntegerFromValue::GetHTMLValue()
{
	return G4UIcommand::ConvertToString(fValue);
}
