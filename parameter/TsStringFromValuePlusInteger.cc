#include "TsStringFromValuePlusInteger.hh"

TsStringFromValuePlusInteger::TsStringFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = value;

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsStringFromValuePlusInteger::~TsStringFromValuePlusInteger()
{
}


G4String TsStringFromValuePlusInteger::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromValuePlusInteger::GetStringValue()
{
	fUsed = true;
	return fValue + G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter));
}


G4String TsStringFromValuePlusInteger::GetHTMLValue()
{
	G4String output;
	output += fValue;
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
