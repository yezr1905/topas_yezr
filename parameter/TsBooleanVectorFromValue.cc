#include "TsBooleanVectorFromValue.hh"

TsBooleanVectorFromValue::TsBooleanVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values)
:TsVParameter(pM, pf, tempParameter)
{
	fLength = nValues;
	fValues = new G4bool [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToBooleanVector(nValues, values,  fValues, fValuesIfParameterNames);
}


TsBooleanVectorFromValue::~TsBooleanVectorFromValue()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsBooleanVectorFromValue::GetType()
{
	G4String type = "bv";
	return type;
}


G4int TsBooleanVectorFromValue::GetVectorLength()
{
	return fLength;
}


G4bool* TsBooleanVectorFromValue::GetBooleanVector()
{
	fUsed = true;
	G4bool* values = new G4bool[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue];
		else
			values[iValue] = EvaluateBooleanParameter(fValuesIfParameterNames[iValue]);
	return values;
}


G4String TsBooleanVectorFromValue::GetHTMLValue()
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
