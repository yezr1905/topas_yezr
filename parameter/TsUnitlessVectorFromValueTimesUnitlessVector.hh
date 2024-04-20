#ifndef TsUnitlessVectorFromValueTimesUnitlessVector_hh
#define TsUnitlessVectorFromValueTimesUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValueTimesUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromValueTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValueTimesUnitlessVector();

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
