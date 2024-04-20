#include "TsStringFromStringPlusInteger.hh"

TsStringFromStringPlusInteger::TsStringFromStringPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "s");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsStringFromStringPlusInteger::~TsStringFromStringPlusInteger()
{
}


G4String TsStringFromStringPlusInteger::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromStringPlusInteger::GetStringValue()
{
	fUsed = true;
	return EvaluateStringParameter(fNameOfOtherParameter1) +
	G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter2));
}


G4String TsStringFromStringPlusInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
