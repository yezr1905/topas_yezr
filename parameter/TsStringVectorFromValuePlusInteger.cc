#include "TsStringVectorFromValuePlusInteger.hh"

TsStringVectorFromValuePlusInteger::TsStringVectorFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4String [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToStringVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "i");
}


TsStringVectorFromValuePlusInteger::~TsStringVectorFromValuePlusInteger()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsStringVectorFromValuePlusInteger::GetType()
{
	G4String type = "sv";
	return type;
}


G4int TsStringVectorFromValuePlusInteger::GetVectorLength()
{
	return fLength;
}


G4String* TsStringVectorFromValuePlusInteger::GetStringVector()
{
	fUsed = true;
	G4String* values = new G4String[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] +
			G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter));
		else
			values[iValue] = EvaluateStringParameter(fValuesIfParameterNames[iValue]) +
			G4UIcommand::ConvertToString(EvaluateIntegerParameter(fNameOfOtherParameter));
	return values;
}


G4String TsStringVectorFromValuePlusInteger::GetHTMLValue()
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
