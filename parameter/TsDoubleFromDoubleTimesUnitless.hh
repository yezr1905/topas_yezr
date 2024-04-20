#ifndef TsDoubleFromDoubleTimesUnitless_hh
#define TsDoubleFromDoubleTimesUnitless_hh

#include "TsVParameter.hh"

class TsDoubleFromDoubleTimesUnitless: public TsVParameter
{
public:
	TsDoubleFromDoubleTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit);

	~TsDoubleFromDoubleTimesUnitless();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4String GetUnit();

	G4double GetDoubleValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
	G4String fUnit;
};

#endif
