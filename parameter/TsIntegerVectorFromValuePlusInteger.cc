#include "TsIntegerVectorFromValuePlusInteger.hh"

TsIntegerVectorFromValuePlusInteger::TsIntegerVectorFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4int [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToIntegerVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsIntegerVectorFromValuePlusInteger::~TsIntegerVectorFromValuePlusInteger()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsIntegerVectorFromValuePlusInteger::GetType()
{
	G4String type = "iv";
	return type;
}


G4int TsIntegerVectorFromValuePlusInteger::GetVectorLength()
{
	return fLength;
}


G4int* TsIntegerVectorFromValuePlusInteger::GetIntegerVector()
{
	fUsed = true;
	G4int* values = new G4int[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] +
			EvaluateIntegerParameter(fNameOfOtherParameter);
		else
			values[iValue] = EvaluateIntegerParameter(fValuesIfParameterNames[iValue]) +
			EvaluateIntegerParameter(fNameOfOtherParameter);
	return values;
}


G4String TsIntegerVectorFromValuePlusInteger::GetHTMLValue()
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
