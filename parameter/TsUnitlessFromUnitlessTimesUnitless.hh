#ifndef TsUnitlessFromUnitlessTimesUnitless_hh
#define TsUnitlessFromUnitlessTimesUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessTimesUnitless: public TsVParameter
{
public:
	TsUnitlessFromUnitlessTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromUnitlessTimesUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
