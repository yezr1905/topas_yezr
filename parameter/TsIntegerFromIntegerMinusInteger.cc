#include "TsIntegerFromIntegerMinusInteger.hh"

TsIntegerFromIntegerMinusInteger::TsIntegerFromIntegerMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsIntegerFromIntegerMinusInteger::~TsIntegerFromIntegerMinusInteger()
{
}


G4String TsIntegerFromIntegerMinusInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerMinusInteger::GetIntegerValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) - EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsIntegerFromIntegerMinusInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
