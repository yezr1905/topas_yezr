#include "TsDoubleFromDoubleMinusDouble.hh"

TsDoubleFromDoubleMinusDouble::TsDoubleFromDoubleMinusDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "d");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "d");
}


TsDoubleFromDoubleMinusDouble::~TsDoubleFromDoubleMinusDouble()
{
}


void TsDoubleFromDoubleMinusDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter1);
	CheckUnitAgreement(fNameOfOtherParameter2);
}


G4String TsDoubleFromDoubleMinusDouble::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDoubleMinusDouble::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromDoubleMinusDouble::GetDoubleValue()
{
	fUsed = true;
	return EvaluateDoubleParameter(fNameOfOtherParameter1) - EvaluateDoubleParameter(fNameOfOtherParameter2);
}


G4String TsDoubleFromDoubleMinusDouble::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	output += " ";
	output += fUnit;
	return output;
}
