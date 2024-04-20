#include "TsStringVectorFromValuePlusString.hh"

TsStringVectorFromValuePlusString::TsStringVectorFromValuePlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										   G4int nValues, G4String* values, const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fLength = nValues;
	fValues = new G4String [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToStringVector(nValues, values,  fValues, fValuesIfParameterNames);

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "s");
}


TsStringVectorFromValuePlusString::~TsStringVectorFromValuePlusString()
{
	delete fValues;
	delete fValuesIfParameterNames;
}


G4String TsStringVectorFromValuePlusString::GetType()
{
	G4String type = "sv";
	return type;
}


G4int TsStringVectorFromValuePlusString::GetVectorLength()
{
	return fLength;
}


G4String* TsStringVectorFromValuePlusString::GetStringVector()
{
	fUsed = true;
	G4String* values = new G4String[fLength];
	for (G4int iValue=0; iValue<fLength; iValue++)
		if (fValuesIfParameterNames[iValue]=="")
			values[iValue] = fValues[iValue] +
			EvaluateStringParameter(fNameOfOtherParameter);
		else
			values[iValue] = EvaluateStringParameter(fValuesIfParameterNames[iValue]) +
			EvaluateStringParameter(fNameOfOtherParameter);
	return values;
}


G4String TsStringVectorFromValuePlusString::GetHTMLValue()
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
