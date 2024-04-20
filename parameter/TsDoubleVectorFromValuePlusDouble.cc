#include "TsDoubleVectorFromValuePlusDouble.hh"

TsDoubleVectorFromValuePlusDouble::TsDoubleVectorFromValuePlusDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter, const G4String& unit)
:TsVParameter(pM, pf, tempParameter), fUnit(unit)
{
	QuitIfMustBeAbsolute();

	CheckUnit(unit);

	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "d");
}


TsDoubleVectorFromValuePlusDouble::~TsDoubleVectorFromValuePlusDouble()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsDoubleVectorFromValuePlusDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleVectorFromValuePlusDouble::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromValuePlusDouble::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromValuePlusDouble::GetVectorLength()
{
	return fLength;
}


G4double* TsDoubleVectorFromValuePlusDouble::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] * fPm->GetUnitValue(fUnit) +
			EvaluateDoubleParameter(fNameOfOtherParameter);
		else
			values[iValue] = EvaluateDoubleParameter(fValuesIfParameterNames[iValue]) +
			EvaluateDoubleParameter(fNameOfOtherParameter);
	return values;
}


G4String TsDoubleVectorFromValuePlusDouble::GetHTMLValue()
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
	output += " + ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
