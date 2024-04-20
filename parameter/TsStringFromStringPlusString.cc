#include "TsStringFromStringPlusString.hh"

TsStringFromStringPlusString::TsStringFromStringPlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "s");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "s");
}


TsStringFromStringPlusString::~TsStringFromStringPlusString()
{
}


G4String TsStringFromStringPlusString::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromStringPlusString::GetStringValue()
{
	fUsed = true;
	return EvaluateStringParameter(fNameOfOtherParameter1) + EvaluateStringParameter(fNameOfOtherParameter2);
}


G4String TsStringFromStringPlusString::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
