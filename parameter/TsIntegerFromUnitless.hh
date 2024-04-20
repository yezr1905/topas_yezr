#ifndef TsIntegerFromUnitless_hh
#define TsIntegerFromUnitless_hh

#include "TsVParameter.hh"

class TsIntegerFromUnitless: public TsVParameter
{
public:
	TsIntegerFromUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter);

	~TsIntegerFromUnitless();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
