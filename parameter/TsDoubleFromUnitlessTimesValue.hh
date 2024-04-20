#ifndef TsDoubleFromUnitlessTimesValue_hh
#define TsDoubleFromUnitlessTimesValue_hh

#include "TsVParameter.hh"

class TsDoubleFromUnitlessTimesValue: public TsVParameter
{
public:
	TsDoubleFromUnitlessTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
									const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit);

	~TsDoubleFromUnitlessTimesValue();

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
