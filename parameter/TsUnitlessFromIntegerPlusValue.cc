#include "TsUnitlessFromIntegerPlusValue.hh"

TsUnitlessFromIntegerPlusValue::TsUnitlessFromIntegerPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessFromIntegerPlusValue::~TsUnitlessFromIntegerPlusValue()
{
}


G4String TsUnitlessFromIntegerPlusValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerPlusValue::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter) + fValue;
}


G4String TsUnitlessFromIntegerPlusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " + ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
