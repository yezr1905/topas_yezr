#ifndef TsDoubleVectorFromValuePlusDoubleVector_hh
#define TsDoubleVectorFromValuePlusDoubleVector_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromValuePlusDoubleVector: public TsVParameter
{
public:
	TsDoubleVectorFromValuePlusDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleVectorFromValuePlusDoubleVector();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4String GetUnit();

	G4int GetVectorLength();

	G4double* GetDoubleVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4double* fValues;
	G4String* fValuesIfParameterNames;
	G4String fNameOfOtherParameter;
	G4String fUnit;
};

#endif
