#include "TsStringFromInteger.hh"

TsStringFromInteger::TsStringFromInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsStringFromInteger::~TsStringFromInteger()
{
}


G4String TsStringFromInteger::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromInteger::GetStringValue()
{
	fUsed = true;
	return G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter));
}


G4String TsStringFromInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
