#include "TsUnitlessFromUnitlessTimesValue.hh"

TsUnitlessFromUnitlessTimesValue::TsUnitlessFromUnitlessTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromUnitlessTimesValue::~TsUnitlessFromUnitlessTimesValue()
{
}


G4String TsUnitlessFromUnitlessTimesValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitlessTimesValue::GetUnitlessValue()
{
	fUsed = true;
	return fValue * EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromUnitlessTimesValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " * ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
