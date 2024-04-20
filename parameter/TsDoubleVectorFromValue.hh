#ifndef TsDoubleVectorFromValue_hh
#define TsDoubleVectorFromValue_hh

#include "TsVParameter.hh"

class TsDoubleVectorFromValue: public TsVParameter
{
public:
	TsDoubleVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& unit);

	~TsDoubleVectorFromValue();

	G4String GetType();

	G4String GetUnit();

	G4int GetVectorLength();

	G4double* GetDoubleVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4double* fValues;
	G4String* fValuesIfParameterNames;
	G4String fUnit;
};

#endif
