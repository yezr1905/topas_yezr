#include "TsIntegerFromIntegerTimesUnitless.hh"

TsIntegerFromIntegerTimesUnitless::TsIntegerFromIntegerTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																	   const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "u");
}


TsIntegerFromIntegerTimesUnitless::~TsIntegerFromIntegerTimesUnitless()
{
}


G4String TsIntegerFromIntegerTimesUnitless::GetType()
{
	G4String type = "i";
	return type;
}


G4int TsIntegerFromIntegerTimesUnitless::GetIntegerValue()
{
	fUsed = true;
	return round( EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateUnitlessParameter(fNameOfOtherParameter2) );
}


G4String TsIntegerFromIntegerTimesUnitless::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
