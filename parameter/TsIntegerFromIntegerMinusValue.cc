#include "TsIntegerFromIntegerMinusValue.hh"

TsIntegerFromIntegerMinusValue::TsIntegerFromIntegerMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromIntegerMinusValue::~TsIntegerFromIntegerMinusValue()
{
}


G4String TsIntegerFromIntegerMinusValue::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerMinusValue::GetIntegerValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter) - fValue;
}


G4String TsIntegerFromIntegerMinusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " - ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
