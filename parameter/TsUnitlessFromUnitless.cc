#include "TsUnitlessFromUnitless.hh"

TsUnitlessFromUnitless::TsUnitlessFromUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsUnitlessFromUnitless::~TsUnitlessFromUnitless()
{
}


G4String TsUnitlessFromUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitless::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateUnitlessParameter(fNameOfOtherParameter);
}


G4String TsUnitlessFromUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
