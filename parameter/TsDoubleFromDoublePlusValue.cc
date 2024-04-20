#include "TsDoubleFromDoublePlusValue.hh"

TsDoubleFromDoublePlusValue::TsDoubleFromDoublePlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
														 const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromDoublePlusValue::~TsDoubleFromDoublePlusValue()
{
}


void TsDoubleFromDoublePlusValue::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromDoublePlusValue::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDoublePlusValue::GetUnit()
{
	return fUnit;
}


G4double TsDoubleFromDoublePlusValue::GetDoubleValue()
{
	fUsed = true;
	return EvaluateDoubleParameter(fNameOfOtherParameter) + fValue * fPm->GetUnitValue(fUnit);
}


G4String TsDoubleFromDoublePlusValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " + ";
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	return output;
}
