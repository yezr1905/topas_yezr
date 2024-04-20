#ifndef TsUnitlessVectorFromValueMinusUnitlessVector_hh
#define TsUnitlessVectorFromValueMinusUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValueMinusUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromValueMinusUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValueMinusUnitlessVector();

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
