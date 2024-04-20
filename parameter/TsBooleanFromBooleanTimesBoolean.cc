#include "TsBooleanFromBooleanTimesBoolean.hh"

TsBooleanFromBooleanTimesBoolean::TsBooleanFromBooleanTimesBoolean(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "b");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "b");
}


TsBooleanFromBooleanTimesBoolean::~TsBooleanFromBooleanTimesBoolean()
{
}


G4String TsBooleanFromBooleanTimesBoolean::GetType()
{
	G4String type = "b";
	return type;
}


G4bool TsBooleanFromBooleanTimesBoolean::GetBooleanValue()
{
	fUsed = true;
	return EvaluateBooleanParameter(fNameOfOtherParameter1) && EvaluateBooleanParameter(fNameOfOtherParameter2);
}


G4String TsBooleanFromBooleanTimesBoolean::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
