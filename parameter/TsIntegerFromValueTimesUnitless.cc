#include "TsIntegerFromValueTimesUnitless.hh"

TsIntegerFromValueTimesUnitless::TsIntegerFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsIntegerFromValueTimesUnitless::~TsIntegerFromValueTimesUnitless()
{
}


G4String TsIntegerFromValueTimesUnitless::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromValueTimesUnitless::GetIntegerValue()
{
	fUsed = true;
	return round( fValue * EvaluateUnitlessParameter(fNameOfOtherParameter) );
}


G4String TsIntegerFromValueTimesUnitless::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
