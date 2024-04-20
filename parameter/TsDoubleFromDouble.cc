#include "TsDoubleFromDouble.hh"

TsDoubleFromDouble::TsDoubleFromDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
									   const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleFromDouble::~TsDoubleFromDouble()
{
}


void TsDoubleFromDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleFromDouble::GetType()
{
	G4String type = "d";
	return type;
}


G4String TsDoubleFromDouble::GetUnit() {
	return fUnit;
}


G4double TsDoubleFromDouble::GetDoubleValue()
{
	fUsed = true;
	return EvaluateDoubleParameter(fNameOfOtherParameter);
}


G4String TsDoubleFromDouble::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	return output;
}
