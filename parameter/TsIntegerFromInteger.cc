#include "TsIntegerFromInteger.hh"

TsIntegerFromInteger::TsIntegerFromInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerFromInteger::~TsIntegerFromInteger()
{
}


G4String TsIntegerFromInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromInteger::GetIntegerValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter);
}


G4String TsIntegerFromInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
