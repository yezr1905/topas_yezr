#include "TsUnitlessFromValueTimesUnitless.hh"

TsUnitlessFromValueTimesUnitless::TsUnitlessFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromValueTimesUnitless::~TsUnitlessFromValueTimesUnitless()
{
}


G4String TsUnitlessFromValueTimesUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromValueTimesUnitless::GetUnitlessValue()
{
	fUsed = true;
	return fValue * EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromValueTimesUnitless::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
