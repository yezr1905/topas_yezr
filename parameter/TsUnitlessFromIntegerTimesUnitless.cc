#include "TsUnitlessFromIntegerTimesUnitless.hh"

TsUnitlessFromIntegerTimesUnitless::TsUnitlessFromIntegerTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "u");
}


TsUnitlessFromIntegerTimesUnitless::~TsUnitlessFromIntegerTimesUnitless()
{
}


G4String TsUnitlessFromIntegerTimesUnitless::GetType()
{
	G4String type = "u";
	return type;
}


G4double TsUnitlessFromIntegerTimesUnitless::GetUnitlessValue()
{
	fUsed = true;
	return EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateUnitlessParameter(fNameOfOtherParameter2);
}


G4String TsUnitlessFromIntegerTimesUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
