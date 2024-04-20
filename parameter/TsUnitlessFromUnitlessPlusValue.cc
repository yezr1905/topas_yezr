#include "TsUnitlessFromUnitlessPlusValue.hh"

TsUnitlessFromUnitlessPlusValue::TsUnitlessFromUnitlessPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromUnitlessPlusValue::~TsUnitlessFromUnitlessPlusValue()
{
}


G4String TsUnitlessFromUnitlessPlusValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitlessPlusValue::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateUnitlessParameter(fNameOfOtherParameter) + fValue;
}


G4String TsUnitlessFromUnitlessPlusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " + ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
