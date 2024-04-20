#include "TsUnitlessFromUnitlessPlusInteger.hh"

TsUnitlessFromUnitlessPlusInteger::TsUnitlessFromUnitlessPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "u");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsUnitlessFromUnitlessPlusInteger::~TsUnitlessFromUnitlessPlusInteger()
{
}


G4String TsUnitlessFromUnitlessPlusInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitlessPlusInteger::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateUnitlessParameter(fNameOfOtherParameter1) +
	EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromUnitlessPlusInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
