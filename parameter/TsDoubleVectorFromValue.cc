#include "TsDoubleVectorFromValue.hh"

TsDoubleVectorFromValue::TsDoubleVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
												 G4int nValues, G4String* values, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	CheckUnit(unit);

	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);
}


TsDoubleVectorFromValue::~TsDoubleVectorFromValue()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsDoubleVectorFromValue::GetUnit()
{
	return fUnit;
}


G4String TsDoubleVectorFromValue::GetType()
{
	G4String type = "dv";
	return type;
}


G4int TsDoubleVectorFromValue::GetVectorLength()
{
	return fLength;
}


G4double* TsDoubleVectorFromValue::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] * fPm->GetUnitValue(fUnit);
		else
			values[iValue] = EvaluateDoubleParameter(fValuesIfParameterNames[iValue]);
	return values;
}


G4String TsDoubleVectorFromValue::GetHTMLValue()
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
	return output;
}
