#ifndef TsUnitlessFromIntegerTimesInteger_hh
#define TsUnitlessFromIntegerTimesInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerTimesInteger: public TsVParameter
{
public:
	TsUnitlessFromIntegerTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromIntegerTimesInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
