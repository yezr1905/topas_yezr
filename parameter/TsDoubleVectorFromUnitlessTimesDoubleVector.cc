#include "TsDoubleVectorFromUnitlessTimesDoubleVector.hh"

TsDoubleVectorFromUnitlessTimesDoubleVector::TsDoubleVectorFromUnitlessTimesDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "u");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "dv");
}


TsDoubleVectorFromUnitlessTimesDoubleVector::~TsDoubleVectorFromUnitlessTimesDoubleVector()
{
}


void TsDoubleVectorFromUnitlessTimesDoubleVector::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter2);
}


G4String TsDoubleVectorFromUnitlessTimesDoubleVector::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromUnitlessTimesDoubleVector::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromUnitlessTimesDoubleVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter2);
}


G4double* TsDoubleVectorFromUnitlessTimesDoubleVector::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = EvaluateUnitlessParameter(fNameOfOtherParameter1) * EvaluateDoubleVector(fNameOfOtherParameter2)[iValue];
	return values;
}


G4String TsDoubleVectorFromUnitlessTimesDoubleVector::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	output += " ";
	output += fUnit;
	return output;
}
