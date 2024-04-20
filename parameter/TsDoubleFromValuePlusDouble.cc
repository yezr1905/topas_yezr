#include "TsDoubleFromValuePlusDouble.hh"

TsDoubleFromValuePlusDouble::TsDoubleFromValuePlusDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														 const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromValuePlusDouble::~TsDoubleFromValuePlusDouble()
{
}


void TsDoubleFromValuePlusDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromValuePlusDouble::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromValuePlusDouble::GetUnit()
{
	return fUnit;
}


G4double TsDoubleFromValuePlusDouble::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit) + EvaluateDoubleParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromValuePlusDouble::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
