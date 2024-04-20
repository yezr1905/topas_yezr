#include "TsStringFromValue.hh"

TsStringFromValue::TsStringFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	fValue = value;
}


TsStringFromValue::~TsStringFromValue()
{
}


G4String TsStringFromValue::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromValue::GetStringValue()
{
	fUsed = true;
	return fValue;
}


G4String TsStringFromValue::GetHTMLValue()
{
	return fValue;
}
