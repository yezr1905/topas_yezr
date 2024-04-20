#include "TsStringVectorFromValue.hh"

TsStringVectorFromValue::TsStringVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   G4int nValues, G4String* values)
:TsVParameter(pM, pf, tempParameter)
{
	fLength = nValues;
	fValues = new G4String [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToStringVector(nValues, values,  fValues, fValuesIfParameterNames);
}


TsStringVectorFromValue::~TsStringVectorFromValue()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsStringVectorFromValue::GetType()
{
	G4String type = "sv";
	return type;
}


G4int TsStringVectorFromValue::GetVectorLength()
{
	return fLength;
}


G4String* TsStringVectorFromValue::GetStringVector()
{
	fUsed = true;
	G4String* values = new G4String[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue];
		else
			values[iValue] = EvaluateStringParameter(fValuesIfParameterNames[iValue]);
	return values;
}


G4String TsStringVectorFromValue::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + fValues[iValue];
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	return output;
}
