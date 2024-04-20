#include "TsUnitlessFromUnitlessMinusValue.hh"

TsUnitlessFromUnitlessMinusValue::TsUnitlessFromUnitlessMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromUnitlessMinusValue::~TsUnitlessFromUnitlessMinusValue()
{
}


G4String TsUnitlessFromUnitlessMinusValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitlessMinusValue::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateUnitlessParameter(fNameOfOtherParameter) - fValue;
}


G4String TsUnitlessFromUnitlessMinusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " - ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
