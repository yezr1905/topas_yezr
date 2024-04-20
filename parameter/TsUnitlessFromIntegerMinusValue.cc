#include "TsUnitlessFromIntegerMinusValue.hh"

TsUnitlessFromIntegerMinusValue::TsUnitlessFromIntegerMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessFromIntegerMinusValue::~TsUnitlessFromIntegerMinusValue()
{
}


G4String TsUnitlessFromIntegerMinusValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerMinusValue::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter) - fValue;
}


G4String TsUnitlessFromIntegerMinusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " - ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
