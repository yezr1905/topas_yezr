#include "TsIntegerFromIntegerTimesValue.hh"

TsIntegerFromIntegerTimesValue::TsIntegerFromIntegerTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter, const G4String& value)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToInteger(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromIntegerTimesValue::~TsIntegerFromIntegerTimesValue()
{
}


G4String TsIntegerFromIntegerTimesValue::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerTimesValue::GetIntegerValue()
{
	fUsed = true;
	return fValue * EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsIntegerFromIntegerTimesValue::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " * ";
	output += G4UIcommand::ConvertToString(fValue);
	return output;
}
