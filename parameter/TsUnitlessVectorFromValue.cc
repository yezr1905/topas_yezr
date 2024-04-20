#include "TsUnitlessVectorFromValue.hh"

TsUnitlessVectorFromValue::TsUnitlessVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values)
:TsVParameter(pM, pf, tempParameter)
{
	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);
}


TsUnitlessVectorFromValue::~TsUnitlessVectorFromValue()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsUnitlessVectorFromValue::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromValue::GetVectorLength()
{
	return fLength;
}


G4double* TsUnitlessVectorFromValue::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue];
		else
			values[iValue] = EvaluateUnitlessParameter(fValuesIfParameterNames[iValue]);
	return values;
}


G4String TsUnitlessVectorFromValue::GetHTMLValue()
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
