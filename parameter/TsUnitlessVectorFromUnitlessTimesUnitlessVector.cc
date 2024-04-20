#include "TsUnitlessVectorFromUnitlessTimesUnitlessVector.hh"

TsUnitlessVectorFromUnitlessTimesUnitlessVector::TsUnitlessVectorFromUnitlessTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
															 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2)
:TsVParameter(pM, pf, tempParameter)
{
	QuitIfMustBeAbsolute();

	fNameOfOtherParameter1 = ParseNameOfOtherParameter(nameOfOtherParameter1, "u");
	fNameOfOtherParameter2 = ParseNameOfOtherParameter(nameOfOtherParameter2, "uv");
}


TsUnitlessVectorFromUnitlessTimesUnitlessVector::~TsUnitlessVectorFromUnitlessTimesUnitlessVector()
{
}


G4String TsUnitlessVectorFromUnitlessTimesUnitlessVector::GetType()
{
	G4String type = "uv";
	return type;
}


G4int TsUnitlessVectorFromUnitlessTimesUnitlessVector::GetVectorLength()
{
	return GetLengthOfOtherParameter(fNameOfOtherParameter2);
}


G4double* TsUnitlessVectorFromUnitlessTimesUnitlessVector::GetUnitlessVector()
{
	fUsed = true;
	G4double* values = new G4double[GetVectorLength()];
	for (G4int iValue=0; iValue<GetVectorLength(); iValue++)
			values[iValue] = EvaluateUnitlessParameter(fNameOfOtherParameter1) * EvaluateUnitlessVector(fNameOfOtherParameter2)[iValue];
	return values;
}


G4String TsUnitlessVectorFromUnitlessTimesUnitlessVector::GetHTMLValue()
{
	G4String output;
	output += EvaluateAsHTML(fNameOfOtherParameter1);
	output += " * ";
	output += EvaluateAsHTML(fNameOfOtherParameter2);
	return output;
}
