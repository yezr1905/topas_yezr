#include "TsDoubleFromValueTimesInteger.hh"

TsDoubleFromValueTimesInteger::TsDoubleFromValueTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															   const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsDoubleFromValueTimesInteger::~TsDoubleFromValueTimesInteger()
{
}


G4String TsDoubleFromValueTimesInteger::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromValueTimesInteger::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromValueTimesInteger::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit) * EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromValueTimesInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	return output;
}
