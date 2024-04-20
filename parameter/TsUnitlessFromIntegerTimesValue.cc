#include "TsUnitlessFromIntegerTimesValue.hh"

TsUnitlessFromIntegerTimesValue::TsUnitlessFromIntegerTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessFromIntegerTimesValue::~TsUnitlessFromIntegerTimesValue()
{
}


G4String TsUnitlessFromIntegerTimesValue::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerTimesValue::GetUnitlessValue()
{
	fUsed = true;
	return fValue * EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromIntegerTimesValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " * ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
