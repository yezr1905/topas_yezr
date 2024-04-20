#ifndef TsDoubleVectorFromValueTimesUnitlessVector_hh
#define TsDoubleVectorFromValueTimesUnitlessVector_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromValueTimesUnitlessVector: public TsVParameter
{
public:
	TsDoubleVectorFromValueTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
											   G4int nValues, G4String* values, const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleVectorFromValueTimesUnitlessVector();

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
