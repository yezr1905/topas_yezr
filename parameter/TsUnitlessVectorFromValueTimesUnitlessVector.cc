#include "TsUnitlessVectorFromValueTimesUnitlessVector.hh"

TsUnitlessVectorFromValueTimesUnitlessVector::TsUnitlessVectorFromValueTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "uv");
}


TsUnitlessVectorFromValueTimesUnitlessVector::~TsUnitlessVectorFromValueTimesUnitlessVector()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsUnitlessVectorFromValueTimesUnitlessVector::CheckRelativeParameterConsistency()
{
	CheckVectorLengthAgreement(fNameOfOtherParameter);
}


G4String TsUnitlessVectorFromValueTimesUnitlessVector::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromValueTimesUnitlessVector::GetVectorLength()
{
	return fLength;
}


G4double* TsUnitlessVectorFromValueTimesUnitlessVector::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] *
			EvaluateUnitlessVector(fNameOfOtherParameter)[iValue];
		else
			values[iValue] = EvaluateUnitlessParameter(fValuesIfParameterNames[iValue]) *
			EvaluateUnitlessVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsUnitlessVectorFromValueTimesUnitlessVector::GetHTMLValue()
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
