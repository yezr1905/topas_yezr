#ifndef TsUnitlessVectorFromValue_hh
#define TsUnitlessVectorFromValue_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValue: public TsVParameter
{
public:
	TsUnitlessVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values);

	~TsUnitlessVectorFromValue();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4double* fValues;
	G4String* fValuesIfParameterNames;
};

#endif
