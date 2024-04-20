#include "TsIntegerFromValuePlusInteger.hh"

TsIntegerFromValuePlusInteger::TsIntegerFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromValuePlusInteger::~TsIntegerFromValuePlusInteger()
{
}


G4String TsIntegerFromValuePlusInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromValuePlusInteger::GetIntegerValue()
{
	fUsed = true;
	return fValue + EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsIntegerFromValuePlusInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
