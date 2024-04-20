#include "TsDoubleFromValueTimesDouble.hh"

TsDoubleFromValueTimesDouble::TsDoubleFromValueTimesDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromValueTimesDouble::~TsDoubleFromValueTimesDouble()
{
}


void TsDoubleFromValueTimesDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromValueTimesDouble::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromValueTimesDouble::GetUnit()
{
	return fUnit;
}


G4double TsDoubleFromValueTimesDouble::GetDoubleValue()
{
	fUsed = true;
	return fValue * EvaluateDoubleParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromValueTimesDouble::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	return output;
}
