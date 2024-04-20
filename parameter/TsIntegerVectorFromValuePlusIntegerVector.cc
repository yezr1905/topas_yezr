#include "TsIntegerVectorFromValuePlusIntegerVector.hh"

TsIntegerVectorFromValuePlusIntegerVector::TsIntegerVectorFromValuePlusIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4int [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToIntegerVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "iv");
}


TsIntegerVectorFromValuePlusIntegerVector::~TsIntegerVectorFromValuePlusIntegerVector()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsIntegerVectorFromValuePlusIntegerVector::CheckRelativeParameterConsistency()
{
	CheckVectorLengthAgreement(fNameOfOtherParameter);
}


G4String TsIntegerVectorFromValuePlusIntegerVector::GetType()
{
	G4String type = "iv";
	return type;
}


G4int TsIntegerVectorFromValuePlusIntegerVector::GetVectorLength()
{
	return fLength;
}


G4int* TsIntegerVectorFromValuePlusIntegerVector::GetIntegerVector()
{
	fUsed = true;
	G4int* values = new G4int[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] +
			EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
		else
			values[iValue] = EvaluateIntegerParameter(fValuesIfParameterNames[iValue]) +
			EvaluateIntegerVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsIntegerVectorFromValuePlusIntegerVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + G4UIcommand::ConvertToString(fValues[iValue]);
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
