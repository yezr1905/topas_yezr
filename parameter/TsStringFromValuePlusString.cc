#include "TsStringFromValuePlusString.hh"

TsStringFromValuePlusString::TsStringFromValuePlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = value;

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "s");
}


TsStringFromValuePlusString::~TsStringFromValuePlusString()
{
}


G4String TsStringFromValuePlusString::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromValuePlusString::GetStringValue()
{
	fUsed = true;
	return fValue + EvaluateStringParameter(fNameOfOtherParameter);
}


G4String TsStringFromValuePlusString::GetHTMLValue()
{
	G4String output;
	output += fValue;
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
