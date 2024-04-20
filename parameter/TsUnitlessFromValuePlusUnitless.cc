#include "TsUnitlessFromValuePlusUnitless.hh"

TsUnitlessFromValuePlusUnitless::TsUnitlessFromValuePlusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromValuePlusUnitless::~TsUnitlessFromValuePlusUnitless()
{
}


G4String TsUnitlessFromValuePlusUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromValuePlusUnitless::GetUnitlessValue()
{
	fUsed = true;
	return fValue + EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromValuePlusUnitless::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
