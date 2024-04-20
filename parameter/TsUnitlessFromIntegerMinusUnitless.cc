#include "TsUnitlessFromIntegerMinusUnitless.hh"

TsUnitlessFromIntegerMinusUnitless::TsUnitlessFromIntegerMinusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "u");
}


TsUnitlessFromIntegerMinusUnitless::~TsUnitlessFromIntegerMinusUnitless()
{
}


G4String TsUnitlessFromIntegerMinusUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerMinusUnitless::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) - EvaluateUnitlessParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromIntegerMinusUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
