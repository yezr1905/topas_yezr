#ifndef TsBooleanVectorFromValue_hh
#define TsBooleanVectorFromValue_hh

#include "TsVParameter.hh"

class TsBooleanVectorFromValue: public TsVParameter
{
public:
	TsBooleanVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values);

	~TsBooleanVectorFromValue();

	G4String GetType();

	G4int GetVectorLength();

	G4bool* GetBooleanVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4bool* fValues;
	G4String* fValuesIfParameterNames;
};

#endif
