#ifndef TsIntegerVectorFromValue_hh
#define TsIntegerVectorFromValue_hh

#include "TsVParameter.hh"

class TsIntegerVectorFromValue: public TsVParameter
{
public:
	TsIntegerVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values);

	~TsIntegerVectorFromValue();

	G4String GetType();

	G4int GetVectorLength();

	G4int* GetIntegerVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4int* fValues;
	G4String* fValuesIfParameterNames;
};

#endif
