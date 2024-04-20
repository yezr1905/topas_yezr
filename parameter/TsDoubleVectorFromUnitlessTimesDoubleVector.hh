#ifndef TsDoubleVectorFromUnitlessTimesDoubleVector_hh
#define TsDoubleVectorFromUnitlessTimesDoubleVector_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromUnitlessTimesDoubleVector: public TsVParameter
{
public:
	TsDoubleVectorFromUnitlessTimesDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& fNameOfOtherParameter1, const G4String& fNameOfOtherParameter2, const G4String& unit);

	~TsDoubleVectorFromUnitlessTimesDoubleVector();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4String GetUnit();

	G4int GetVectorLength();

	G4double* GetDoubleVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
	G4String fUnit;
};

#endif
