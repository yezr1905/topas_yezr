#include "TsUnitlessFromValuePlusInteger.hh"

TsUnitlessFromValuePlusInteger::TsUnitlessFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessFromValuePlusInteger::~TsUnitlessFromValuePlusInteger()
{
}


G4String TsUnitlessFromValuePlusInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromValuePlusInteger::GetUnitlessValue()
{
	fUsed = true;
	return fValue + EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromValuePlusInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
