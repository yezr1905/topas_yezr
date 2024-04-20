#include "TsUnitlessFromValue.hh"

TsUnitlessFromValue::TsUnitlessFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	fValue = ConvertToDouble(value);
}


TsUnitlessFromValue::~TsUnitlessFromValue()
{
}


G4String TsUnitlessFromValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromValue::GetUnitlessValue()
{
	fUsed = true;
	return fValue;
}


G4String TsUnitlessFromValue::GetHTMLValue()
{
	return G4UIcommand::ConvertToString(fValue);
}
