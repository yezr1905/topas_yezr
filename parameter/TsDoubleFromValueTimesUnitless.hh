#ifndef TsDoubleFromValueTimesUnitless_hh
#define TsDoubleFromValueTimesUnitless_hh

#include "TsVParameter.hh"

class TsDoubleFromValueTimesUnitless: public TsVParameter
{
public:
	TsDoubleFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
									const G4String& value, const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleFromValueTimesUnitless();

	G4String GetType();

	G4String GetUnit();

	G4double GetDoubleValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
	G4String fUnit;
};

#endif
