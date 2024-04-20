#include "TsDoubleFromDoubleTimesUnitless.hh"

TsDoubleFromDoubleTimesUnitless::TsDoubleFromDoubleTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "d");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "u");
}


TsDoubleFromDoubleTimesUnitless::~TsDoubleFromDoubleTimesUnitless()
{
}


void TsDoubleFromDoubleTimesUnitless::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter1);
}


G4String TsDoubleFromDoubleTimesUnitless::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDoubleTimesUnitless::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromDoubleTimesUnitless::GetDoubleValue()
{
	fUsed = true;
	return EvaluateDoubleParameter(fNameOfOtherParameter1) * EvaluateUnitlessParameter(fNameOfOtherParameter2);
}


G4String TsDoubleFromDoubleTimesUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	output += " ";
	output += fUnit;
	return output;
}
