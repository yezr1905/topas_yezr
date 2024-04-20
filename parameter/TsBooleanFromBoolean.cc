#include "TsBooleanFromBoolean.hh"

TsBooleanFromBoolean::TsBooleanFromBoolean(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "b");
}


TsBooleanFromBoolean::~TsBooleanFromBoolean()
{
}


G4String TsBooleanFromBoolean::GetType()
{
	G4String type = "b";
	return type;
}


G4bool TsBooleanFromBoolean::GetBooleanValue()
{
	fUsed = true;
	return EvaluateBooleanParameter(fNameOfOtherParameter);
}


G4String TsBooleanFromBoolean::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
