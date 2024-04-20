#ifndef TsDoubleFromValue_hh
#define TsDoubleFromValue_hh

#include "TsVParameter.hh"

class TsDoubleFromValue: public TsVParameter
{
public:
	TsDoubleFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
					   const G4String& value, const G4String& unit);

	~TsDoubleFromValue();

	G4String GetType();

	G4String GetUnit();

	G4double GetDoubleValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fUnit;
};

#endif
