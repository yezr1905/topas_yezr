#include "TsIntegerFromIntegerPlusValue.hh"

TsIntegerFromIntegerPlusValue::TsIntegerFromIntegerPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromIntegerPlusValue::~TsIntegerFromIntegerPlusValue()
{
}


G4String TsIntegerFromIntegerPlusValue::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerPlusValue::GetIntegerValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter) + fValue;
}


G4String TsIntegerFromIntegerPlusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " + ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
