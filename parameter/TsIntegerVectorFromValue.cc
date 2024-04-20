#include "TsIntegerVectorFromValue.hh"

TsIntegerVectorFromValue::TsIntegerVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values)
:TsVParameter(pM, pf, tempParameter)
{
	fLength = nValues;
	fValues = new G4int [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToIntegerVector(nValues, values,  fValues, fValuesIfParameterNames);
}


TsIntegerVectorFromValue::~TsIntegerVectorFromValue()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsIntegerVectorFromValue::GetType()
{
	G4String type = "iv";
	return type;
}


G4int TsIntegerVectorFromValue::GetVectorLength()
{
	return fLength;
}


G4int* TsIntegerVectorFromValue::GetIntegerVector()
{
	fUsed = true;
	G4int* values = new G4int[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue];
		else
			values[iValue] = EvaluateIntegerParameter(fValuesIfParameterNames[iValue]);
	return values;
}


G4String TsIntegerVectorFromValue::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + G4UIcommand::ConvertToString(fValues[iValue]);
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	return output;
}
