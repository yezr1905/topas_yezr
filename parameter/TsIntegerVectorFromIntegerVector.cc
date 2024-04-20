#include "TsIntegerVectorFromIntegerVector.hh"

TsIntegerVectorFromIntegerVector::TsIntegerVectorFromIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "iv");
}


TsIntegerVectorFromIntegerVector::~TsIntegerVectorFromIntegerVector()
{
}


G4String TsIntegerVectorFromIntegerVector::GetType()
{
	G4String type = "iv";
	return type;
}


G4int TsIntegerVectorFromIntegerVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4int* TsIntegerVectorFromIntegerVector::GetIntegerVector()
{
	fUsed = true;
	return EvaluateIntegerVector(fNameOfOtherParameter);
}


G4String TsIntegerVectorFromIntegerVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(GetVectorLength());
	output += " ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
