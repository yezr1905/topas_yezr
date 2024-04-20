#include "TsUnitlessFromIntegerTimesInteger.hh"

TsUnitlessFromIntegerTimesInteger::TsUnitlessFromIntegerTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "i");
}


TsUnitlessFromIntegerTimesInteger::~TsUnitlessFromIntegerTimesInteger()
{
}


G4String TsUnitlessFromIntegerTimesInteger::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerTimesInteger::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateIntegerParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromIntegerTimesInteger::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
