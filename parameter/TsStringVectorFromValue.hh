#ifndef TsStringVectorFromValue_hh
#define TsStringVectorFromValue_hh

#include "TsVParameter.hh"

class TsStringVectorFromValue: public TsVParameter
{
public:
	TsStringVectorFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 G4int nValues, G4String* values);

	~TsStringVectorFromValue();

	G4String GetType();

	G4int GetVectorLength();

	G4String* GetStringVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4String* fValues;
	G4String* fValuesIfParameterNames;
};

#endif
