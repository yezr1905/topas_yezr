#ifndef TsIntegerVectorFromIntegerTimesIntegerVector_hh
#define TsIntegerVectorFromIntegerTimesIntegerVector_hh

#include "TsVParameter.hh"

class TsIntegerVectorFromIntegerTimesIntegerVector: public TsVParameter
{
public:
	TsIntegerVectorFromIntegerTimesIntegerVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& fNameOfOtherParameter1, const G4String& fNameOfOtherParameter2);

	~TsIntegerVectorFromIntegerTimesIntegerVector();

	G4String GetType();

	G4int GetVectorLength();

	G4int* GetIntegerVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
