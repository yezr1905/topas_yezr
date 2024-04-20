#include "TsDoubleFromValueMinusDouble.hh"

TsDoubleFromValueMinusDouble::TsDoubleFromValueMinusDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														 const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromValueMinusDouble::~TsDoubleFromValueMinusDouble()
{
}


void TsDoubleFromValueMinusDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromValueMinusDouble::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromValueMinusDouble::GetUnit()
{
	return fUnit;
}


G4double TsDoubleFromValueMinusDouble::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit) - EvaluateDoubleParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromValueMinusDouble::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
