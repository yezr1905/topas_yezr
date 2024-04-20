#ifndef TsIntegerVectorFromValueTimesInteger_hh
#define TsIntegerVectorFromValueTimesInteger_hh

#include "TsVParameter.hh"

class TsIntegerVectorFromValueTimesInteger: public TsVParameter
{
public:
	TsIntegerVectorFromValueTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsIntegerVectorFromValueTimesInteger();

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
