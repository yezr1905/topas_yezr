#include "TsUnitlessFromValueMinusInteger.hh"

TsUnitlessFromValueMinusInteger::TsUnitlessFromValueMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& value, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fValue = ConvertToDouble(value);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessFromValueMinusInteger::~TsUnitlessFromValueMinusInteger()
{
}


G4String TsUnitlessFromValueMinusInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromValueMinusInteger::GetUnitlessValue()
{
	fUsed = true;
	return fValue - EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromValueMinusInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fValue);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
