#include "TsUnitlessVectorFromValueTimesIntegerVector.hh"

TsUnitlessVectorFromValueTimesIntegerVector::TsUnitlessVectorFromValueTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "iv");
}


TsUnitlessVectorFromValueTimesIntegerVector::~TsUnitlessVectorFromValueTimesIntegerVector()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsUnitlessVectorFromValueTimesIntegerVector::CheckRelativeParameterConsistency()
{
	CheckVectorLengthAgreement(fNameOfOtherParameter);
}


G4String TsUnitlessVectorFromValueTimesIntegerVector::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromValueTimesIntegerVector::GetVectorLength()
{
	return fLength;
}


G4double* TsUnitlessVectorFromValueTimesIntegerVector::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] *
			EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
		else
			values[iValue] = EvaluateUnitlessParameter(fValuesIfParameterNames[iValue]) *
			EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsUnitlessVectorFromValueTimesIntegerVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + G4UIcommand::ConvertToString(fValues[iValue]);
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
