#ifndef TsDoubleVectorFromScaleTimesDoubleVector_hh
#define TsDoubleVectorFromScaleTimesDoubleVector_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromScaleTimesDoubleVector: public TsVParameter
{
public:
	TsDoubleVectorFromScaleTimesDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleVectorFromScaleTimesDoubleVector();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4String GetUnit();

	G4int GetVectorLength();

	G4double* GetDoubleVector();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
	G4String fUnit;
};

#endif
