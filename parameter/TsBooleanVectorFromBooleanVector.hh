#ifndef TsBooleanVectorFromBooleanVector_hh
#define TsBooleanVectorFromBooleanVector_hh

#include "TsVParameter.hh"

class TsBooleanVectorFromBooleanVector: public TsVParameter
{
public:
	TsBooleanVectorFromBooleanVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								     const G4String& nameOfOtherParameter);

	~TsBooleanVectorFromBooleanVector();

	G4String GetType();

	G4int GetVectorLength();

	G4bool* GetBooleanVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
