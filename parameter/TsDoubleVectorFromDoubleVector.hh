#ifndef TsDoubleVectorFromDoubleVector_hh
#define TsDoubleVectorFromDoubleVector_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromDoubleVector: public TsVParameter
{
public:
	TsDoubleVectorFromDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								     const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleVectorFromDoubleVector();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4String GetUnit();

	G4int GetVectorLength();

	G4double* GetDoubleVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
	G4String fUnit;
};

#endif
