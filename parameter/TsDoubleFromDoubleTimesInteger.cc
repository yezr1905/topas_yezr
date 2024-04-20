#include "TsDoubleFromDoubleTimesInteger.hh"

TsDoubleFromDoubleTimesInteger::TsDoubleFromDoubleTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "d");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsDoubleFromDoubleTimesInteger::~TsDoubleFromDoubleTimesInteger()
{
}


void TsDoubleFromDoubleTimesInteger::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter1);
}


G4String TsDoubleFromDoubleTimesInteger::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDoubleTimesInteger::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromDoubleTimesInteger::GetDoubleValue()
{
	fUsed = true;
	return EvaluateDoubleParameter(fNameOfOtherParameter1) * EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsDoubleFromDoubleTimesInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	output += " ";
	output += fUnit;
	return output;
}
