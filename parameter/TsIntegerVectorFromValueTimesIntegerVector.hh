#ifndef TsIntegerVectorFromValueTimesIntegerVector_hh
#define TsIntegerVectorFromValueTimesIntegerVector_hh

#include "TsVParameter.hh"

class TsIntegerVectorFromValueTimesIntegerVector: public TsVParameter
{
public:
	TsIntegerVectorFromValueTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsIntegerVectorFromValueTimesIntegerVector();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4int GetVectorLength();

	G4int* GetIntegerVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4int* fValues;
	G4String* fValuesIfParameterNames;
	G4String fNameOfOtherParameter;
};

#endif
