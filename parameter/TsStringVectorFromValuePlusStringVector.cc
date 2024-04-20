#include "TsStringVectorFromValuePlusStringVector.hh"

TsStringVectorFromValuePlusStringVector::TsStringVectorFromValuePlusStringVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4String [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToStringVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "sv");
}


TsStringVectorFromValuePlusStringVector::~TsStringVectorFromValuePlusStringVector()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsStringVectorFromValuePlusStringVector::CheckRelativeParameterConsistency()
{
	CheckVectorLengthAgreement(fNameOfOtherParameter);
}


G4String TsStringVectorFromValuePlusStringVector::GetType()
{
	G4String type = "sv";
	return type;
}


G4int TsStringVectorFromValuePlusStringVector::GetVectorLength()
{
	return fLength;
}


G4String* TsStringVectorFromValuePlusStringVector::GetStringVector()
{
	fUsed = true;
	G4String* values = new G4String[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] +
			EvaluateStringVector(fNameOfOtherParameter)[iValue];
		else
			values[iValue] = EvaluateStringParameter(fValuesIfParameterNames[iValue]) +
			EvaluateStringVector(fNameOfOtherParameter)[iValue];
	return values;
}


G4String TsStringVectorFromValuePlusStringVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + fValues[iValue];
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
