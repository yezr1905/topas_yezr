#include "TsStringFromIntegerPlusString.hh"

TsStringFromIntegerPlusString::TsStringFromIntegerPlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "s");
}


TsStringFromIntegerPlusString::~TsStringFromIntegerPlusString()
{
}


G4String TsStringFromIntegerPlusString::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromIntegerPlusString::GetStringValue()
{
	fUsed = true;
	return G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter1)) +
	EvaluateStringParameter(fNameOfOtherParameter2);
}


G4String TsStringFromIntegerPlusString::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
