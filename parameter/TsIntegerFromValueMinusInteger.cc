#include "TsIntegerFromValueMinusInteger.hh"

TsIntegerFromValueMinusInteger::TsIntegerFromValueMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromValueMinusInteger::~TsIntegerFromValueMinusInteger()
{
}


G4String TsIntegerFromValueMinusInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromValueMinusInteger::GetIntegerValue()
{
	fUsed = true;
	return fValue - EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsIntegerFromValueMinusInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
