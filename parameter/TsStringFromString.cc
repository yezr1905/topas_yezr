#include "TsStringFromString.hh"

TsStringFromString::TsStringFromString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "s");
}


TsStringFromString::~TsStringFromString()
{
}


G4String TsStringFromString::GetType()
{
	G4String type = "s";
	return type;
}


G4String TsStringFromString::GetStringValue()
{
	fUsed = true;
	return EvaluateStringParameter(fNameOfOtherParameter);
}


G4String TsStringFromString::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
