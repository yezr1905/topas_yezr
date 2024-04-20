#include "TsIntegerFromIntegerPlusInteger.hh"

TsIntegerFromIntegerPlusInteger::TsIntegerFromIntegerPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsIntegerFromIntegerPlusInteger::~TsIntegerFromIntegerPlusInteger()
{
}


G4String TsIntegerFromIntegerPlusInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerPlusInteger::GetIntegerValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) + EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsIntegerFromIntegerPlusInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
