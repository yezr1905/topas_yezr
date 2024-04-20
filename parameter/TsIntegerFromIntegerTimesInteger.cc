#include "TsIntegerFromIntegerTimesInteger.hh"

TsIntegerFromIntegerTimesInteger::TsIntegerFromIntegerTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsIntegerFromIntegerTimesInteger::~TsIntegerFromIntegerTimesInteger()
{
}


G4String TsIntegerFromIntegerTimesInteger::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerTimesInteger::GetIntegerValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsIntegerFromIntegerTimesInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
