#ifndef TsIntegerFromValueTimesUnitless_hh
#define TsIntegerFromValueTimesUnitless_hh

#include "TsVParameter.hh"

class TsIntegerFromValueTimesUnitless: public TsVParameter
{
public:
	TsIntegerFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsIntegerFromValueTimesUnitless();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
