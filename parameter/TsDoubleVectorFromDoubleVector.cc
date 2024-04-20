#include "TsDoubleVectorFromDoubleVector.hh"

TsDoubleVectorFromDoubleVector::TsDoubleVectorFromDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																   const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "dv");
}


TsDoubleVectorFromDoubleVector::~TsDoubleVectorFromDoubleVector()
{
}


void TsDoubleVectorFromDoubleVector::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleVectorFromDoubleVector::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromDoubleVector::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromDoubleVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4double* TsDoubleVectorFromDoubleVector::GetDoubleVector()
{
	fUsed = true;
	return EvaluateDoubleVector(fNameOfOtherParameter);
}


G4String TsDoubleVectorFromDoubleVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(GetVectorLength());
	output += " ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	output += " ";
	output += fUnit;
	return output;
}
