#include "TsUnitlessFromUnitlessPlusUnitless.hh"

TsUnitlessFromUnitlessPlusUnitless::TsUnitlessFromUnitlessPlusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "u");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "u");
}


TsUnitlessFromUnitlessPlusUnitless::~TsUnitlessFromUnitlessPlusUnitless()
{
}


G4String TsUnitlessFromUnitlessPlusUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitlessPlusUnitless::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateUnitlessParameter(fNameOfOtherParameter1) +
	EvaluateUnitlessParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromUnitlessPlusUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
