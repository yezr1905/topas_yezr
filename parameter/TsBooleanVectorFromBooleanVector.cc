#include "TsBooleanVectorFromBooleanVector.hh"

TsBooleanVectorFromBooleanVector::TsBooleanVectorFromBooleanVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "bv");
}


TsBooleanVectorFromBooleanVector::~TsBooleanVectorFromBooleanVector()
{
}


G4String TsBooleanVectorFromBooleanVector::GetType()
{
	G4String type = "bv";
	return type;
}


G4int TsBooleanVectorFromBooleanVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4bool* TsBooleanVectorFromBooleanVector::GetBooleanVector()
{
	fUsed = true;
	return EvaluateBooleanVector(fNameOfOtherParameter);
}


G4String TsBooleanVectorFromBooleanVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(GetVectorLength());
	output += " ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
