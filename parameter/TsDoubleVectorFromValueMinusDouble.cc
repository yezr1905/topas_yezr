#include "TsDoubleVectorFromValueMinusDouble.hh"

TsDoubleVectorFromValueMinusDouble::TsDoubleVectorFromValueMinusDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
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


TsDoubleVectorFromValueMinusDouble::~TsDoubleVectorFromValueMinusDouble()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


void TsDoubleVectorFromValueMinusDouble::CheckRelativeParameterConsistency()
{
	CheckUnitAgreement(fNameOfOtherParameter);
}


G4String TsDoubleVectorFromValueMinusDouble::GetType()
{
	G4String type = "dv";
	return type;
}


G4String TsDoubleVectorFromValueMinusDouble::GetUnit() {
	return fUnit;
}


G4int TsDoubleVectorFromValueMinusDouble::GetVectorLength()
{
	return fLength;
}


G4double* TsDoubleVectorFromValueMinusDouble::GetDoubleVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] * fPm->GetUnitValue(fUnit) -
			EvaluateDoubleParameter(fNameOfOtherParameter);
		else
			values[iValue] = EvaluateDoubleParameter(fValuesIfParameterNames[iValue]) -
			EvaluateDoubleParameter(fNameOfOtherParameter);
	return values;
}


G4String TsDoubleVectorFromValueMinusDouble::GetHTMLValue()
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
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
