#include "TsStringFromIntegerPlusValue.hh"

TsStringFromIntegerPlusValue::TsStringFromIntegerPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = value;

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsStringFromIntegerPlusValue::~TsStringFromIntegerPlusValue()
{
}


G4String TsStringFromIntegerPlusValue::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromIntegerPlusValue::GetStringValue()
{
	fUsed = true;
	return G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter)) + fValue;
}


G4String TsStringFromIntegerPlusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " + ";
	output += fValue;
	return output;
}
