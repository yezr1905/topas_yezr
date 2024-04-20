#include "TsUnitlessFromValueMinusUnitless.hh"

TsUnitlessFromValueMinusUnitless::TsUnitlessFromValueMinusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromValueMinusUnitless::~TsUnitlessFromValueMinusUnitless()
{
}


G4String TsUnitlessFromValueMinusUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromValueMinusUnitless::GetUnitlessValue()
{
	fUsed = true;
	return fValue - EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromValueMinusUnitless::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
