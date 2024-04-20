#include "TsDoubleVectorFromIntegerTimesDoubleVector.hh"

TsDoubleVectorFromIntegerTimesDoubleVector::TsDoubleVectorFromIntegerTimesDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "i");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "dv");
}


TsDoubleVectorFromIntegerTimesDoubleVector::~TsDoubleVectorFromIntegerTimesDoubleVector()
{
}


void TsDoubleVectorFromIntegerTimesDoubleVector::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter2);
}


G4String TsDoubleVectorFromIntegerTimesDoubleVector::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromIntegerTimesDoubleVector::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromIntegerTimesDoubleVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter2);
}


G4double* TsDoubleVectorFromIntegerTimesDoubleVector::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = EvaluateIntegerParameter(fNameOfOtherParameter1) * EvaluateDoubleVector(fNameOfOtherParameter2)[iValue];
	return values;
}


G4String TsDoubleVectorFromIntegerTimesDoubleVector::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	output += " ";
	output += fUnit;
	return output;
}
