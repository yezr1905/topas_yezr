#include "TsDoubleVectorFromValueTimesIntegerVector.hh"

TsDoubleVectorFromValueTimesIntegerVector::TsDoubleVectorFromValueTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "iv");
}


TsDoubleVectorFromValueTimesIntegerVector::~TsDoubleVectorFromValueTimesIntegerVector()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsDoubleVectorFromValueTimesIntegerVector::CheckRelativeParameterConsistency()
{
	CheckVectorLengthAgreement(fNameOfOtherParameter);
}


G4String TsDoubleVectorFromValueTimesIntegerVector::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromValueTimesIntegerVector::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromValueTimesIntegerVector::GetVectorLength()
{
	return fLength;
}


G4double* TsDoubleVectorFromValueTimesIntegerVector::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] * fPm->GetUnitValue(fUnit) *
			EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
		else
			values[iValue] = EvaluateDoubleParameter(fValuesIfParameterNames[iValue]) *
			EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsDoubleVectorFromValueTimesIntegerVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + G4UIcommand::ConvertToString(fValues[iValue]);
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	output += " ";
	output += fUnit;
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
