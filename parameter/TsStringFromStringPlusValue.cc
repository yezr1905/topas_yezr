#include "TsStringFromStringPlusValue.hh"

TsStringFromStringPlusValue::TsStringFromStringPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = value;

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "s");
}


TsStringFromStringPlusValue::~TsStringFromStringPlusValue()
{
}


G4String TsStringFromStringPlusValue::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromStringPlusValue::GetStringValue()
{
	fUsed = true;
	return EvaluateStringParameter(fNameOfOtherParameter) + fValue;
}


G4String TsStringFromStringPlusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " + ";
	output += fValue;
	return output;
}
