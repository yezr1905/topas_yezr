#ifndef TsDoubleVectorFromValueTimesDouble_hh
#define TsDoubleVectorFromValueTimesDouble_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromValueTimesDouble: public TsVParameter
{
public:
	TsDoubleVectorFromValueTimesDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleVectorFromValueTimesDouble();

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
