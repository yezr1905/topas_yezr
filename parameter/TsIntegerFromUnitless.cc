#include "TsIntegerFromUnitless.hh"

TsIntegerFromUnitless::TsIntegerFromUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "u");
}


TsIntegerFromUnitless::~TsIntegerFromUnitless()
{
}


G4String TsIntegerFromUnitless::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromUnitless::GetIntegerValue()
{
	fUsed = true;
	return round(EvaluateUnitlessParameter(fNameOfOtherParameter));
}


G4String TsIntegerFromUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
