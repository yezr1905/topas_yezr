#include "TsUnitlessFromIntegerMinusInteger.hh"

TsUnitlessFromIntegerMinusInteger::TsUnitlessFromIntegerMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsUnitlessFromIntegerMinusInteger::~TsUnitlessFromIntegerMinusInteger()
{
}


G4String TsUnitlessFromIntegerMinusInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerMinusInteger::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) - EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromIntegerMinusInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
