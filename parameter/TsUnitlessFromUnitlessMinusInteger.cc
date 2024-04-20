#include "TsUnitlessFromUnitlessMinusInteger.hh"

TsUnitlessFromUnitlessMinusInteger::TsUnitlessFromUnitlessMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "u");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsUnitlessFromUnitlessMinusInteger::~TsUnitlessFromUnitlessMinusInteger()
{
}


G4String TsUnitlessFromUnitlessMinusInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromUnitlessMinusInteger::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateUnitlessParameter(fNameOfOtherParameter1) -
	EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromUnitlessMinusInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
