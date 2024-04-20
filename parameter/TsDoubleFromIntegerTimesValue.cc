#include "TsDoubleFromIntegerTimesValue.hh"

TsDoubleFromIntegerTimesValue::TsDoubleFromIntegerTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															   const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsDoubleFromIntegerTimesValue::~TsDoubleFromIntegerTimesValue()
{
}


G4String TsDoubleFromIntegerTimesValue::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromIntegerTimesValue::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromIntegerTimesValue::GetDoubleValue()
{
	fUsed = true;
	return fValue * fPm->GetUnitValue(fUnit) * EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromIntegerTimesValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " * ";
	output += G4UIcommand::ConvertToString(fValue);
	output += " ";
	output += fUnit;
	return output;
}
