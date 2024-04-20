#ifndef TsIntegerVectorFromScaleTimesIntegerVector_hh
#define TsIntegerVectorFromScaleTimesIntegerVector_hh

#include "TsVParameter.hh"

class TsIntegerVectorFromScaleTimesIntegerVector: public TsVParameter
{
public:
	TsIntegerVectorFromScaleTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& value, const G4String& nameOfOtherParameter);

	~TsIntegerVectorFromScaleTimesIntegerVector();

	G4String GetType();

	G4int GetVectorLength();

	G4int* GetIntegerVector();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
