#ifndef TsIntegerFromIntegerTimesUnitless_hh
#define TsIntegerFromIntegerTimesUnitless_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerTimesUnitless: public TsVParameter
{
public:
	TsIntegerFromIntegerTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsIntegerFromIntegerTimesUnitless();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
