#include "TsIntegerFromValueTimesInteger.hh"

TsIntegerFromValueTimesInteger::TsIntegerFromValueTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromValueTimesInteger::~TsIntegerFromValueTimesInteger()
{
}


G4String TsIntegerFromValueTimesInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromValueTimesInteger::GetIntegerValue()
{
	fUsed = true;
	return fValue * EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsIntegerFromValueTimesInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
