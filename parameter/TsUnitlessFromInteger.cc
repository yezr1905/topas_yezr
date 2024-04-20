#include "TsUnitlessFromInteger.hh"

TsUnitlessFromInteger::TsUnitlessFromInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessFromInteger::~TsUnitlessFromInteger()
{
}


G4String TsUnitlessFromInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromInteger::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
