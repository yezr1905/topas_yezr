#ifndef TsDoubleVectorFromIntegerTimesDoubleVector_hh
#define TsDoubleVectorFromIntegerTimesDoubleVector_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromIntegerTimesDoubleVector: public TsVParameter
{
public:
	TsDoubleVectorFromIntegerTimesDoubleVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& fNameOfOtherParameter1, const G4String& fNameOfOtherParameter2, const G4String& unit);

	~TsDoubleVectorFromIntegerTimesDoubleVector();

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
