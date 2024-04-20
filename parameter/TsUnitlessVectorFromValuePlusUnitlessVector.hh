#ifndef TsUnitlessVectorFromValuePlusUnitlessVector_hh
#define TsUnitlessVectorFromValuePlusUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValuePlusUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromValuePlusUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValuePlusUnitlessVector();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4double* fValues;
	G4String* fValuesIfParameterNames;
	G4String fNameOfOtherParameter;
};

#endif
