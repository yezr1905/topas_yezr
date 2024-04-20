#include "TsStringVectorFromStringVector.hh"

TsStringVectorFromStringVector::TsStringVectorFromStringVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "sv");
}


TsStringVectorFromStringVector::~TsStringVectorFromStringVector()
{
}


G4String TsStringVectorFromStringVector::GetType()
{
	G4String type = "sv";
	return type;
}


G4int TsStringVectorFromStringVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4String* TsStringVectorFromStringVector::GetStringVector()
{
	fUsed = true;
	return EvaluateStringVector(fNameOfOtherParameter);
}


G4String TsStringVectorFromStringVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(GetVectorLength());
	output += " ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
