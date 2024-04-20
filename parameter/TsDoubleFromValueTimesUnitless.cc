#include "TsDoubleFromValueTimesUnitless.hh"

TsDoubleFromValueTimesUnitless::TsDoubleFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																 const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsDoubleFromValueTimesUnitless::~TsDoubleFromValueTimesUnitless()
{
}


G4String TsDoubleFromValueTimesUnitless::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromValueTimesUnitless::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromValueTimesUnitless::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit) * EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromValueTimesUnitless::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	return output;
}
