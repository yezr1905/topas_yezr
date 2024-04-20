#include "TsUnitlessVectorFromUnitlessVector.hh"

TsUnitlessVectorFromUnitlessVector::TsUnitlessVectorFromUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
																   const G4String& nameOfOtherParameter)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter = ParseNameOfOtherParameter(nameOfOtherParameter, "uv");
}


TsUnitlessVectorFromUnitlessVector::~TsUnitlessVectorFromUnitlessVector()
{
}


G4String TsUnitlessVectorFromUnitlessVector::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromUnitlessVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter);
}


G4double* TsUnitlessVectorFromUnitlessVector::GetUnitlessVector()
{
	fUsed = true;
	return EvaluateUnitlessVector(fNameOfOtherParameter);
}


G4String TsUnitlessVectorFromUnitlessVector::GetHTMLValue()
{
	G4String output;
	output += G4UIcommand::ConvertToString(GetVectorLength());
	output += " ";
	output += EvaluateAsHTML(fNameOfOtherParameter);
	return output;
}
