#ifndef TsUnitlessFromIntegerTimesUnitless_hh
#define TsUnitlessFromIntegerTimesUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerTimesUnitless: public TsVParameter
{
public:
	TsUnitlessFromIntegerTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromIntegerTimesUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
