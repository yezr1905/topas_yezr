#ifndef TsIntegerFromIntegerTimesInteger_hh
#define TsIntegerFromIntegerTimesInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerTimesInteger: public TsVParameter
{
public:
	TsIntegerFromIntegerTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsIntegerFromIntegerTimesInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
