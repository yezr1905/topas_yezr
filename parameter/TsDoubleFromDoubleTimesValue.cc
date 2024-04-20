#include "TsDoubleFromDoubleTimesValue.hh"

TsDoubleFromDoubleTimesValue::TsDoubleFromDoubleTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromDoubleTimesValue::~TsDoubleFromDoubleTimesValue()
{
}


void TsDoubleFromDoubleTimesValue::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromDoubleTimesValue::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDoubleTimesValue::GetUnit()
{
	return fUnit;
}


G4double TsDoubleFromDoubleTimesValue::GetDoubleValue()
{
	fUsed = true;
	return fValue * EvaluateDoubleParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromDoubleTimesValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	output += " * ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
