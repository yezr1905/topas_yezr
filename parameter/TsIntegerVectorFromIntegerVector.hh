#ifndef TsIntegerVectorFromIntegerVector_hh
#define TsIntegerVectorFromIntegerVector_hh

#include "TsVParameter.hh"

class TsIntegerVectorFromIntegerVector: public TsVParameter
{
public:
	TsIntegerVectorFromIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								     const G4String& nameOfOtherParameter);

	~TsIntegerVectorFromIntegerVector();

	G4String GetType();

	G4int GetVectorLength();

	G4int* GetIntegerVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
