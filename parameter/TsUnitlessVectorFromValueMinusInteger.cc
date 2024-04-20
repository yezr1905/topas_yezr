#include "TsUnitlessVectorFromValueMinusInteger.hh"

TsUnitlessVectorFromValueMinusInteger::TsUnitlessVectorFromValueMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsUnitlessVectorFromValueMinusInteger::~TsUnitlessVectorFromValueMinusInteger()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsUnitlessVectorFromValueMinusInteger::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromValueMinusInteger::GetVectorLength()
{
	return fLength;
}


G4double* TsUnitlessVectorFromValueMinusInteger::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] -
			EvaluateIntegerParameter(fNameOfOtherParameter);
		else
			values[iValue] = EvaluateUnitlessParameter(fValuesIfParameterNames[iValue]) -
			EvaluateIntegerParameter(fNameOfOtherParameter);
	return values;
}


G4String TsUnitlessVectorFromValueMinusInteger::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(fLength);
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			output+= " " + G4UIcommand::ConvertToString(fValues[iValue]);
		else
			output+= " " + EvaluateAsHTML(fValuesIfParameterNames[iValue]);
	output += " - ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
