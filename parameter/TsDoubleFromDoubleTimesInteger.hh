#ifndef TsDoubleFromDoubleTimesInteger_hh
#define TsDoubleFromDoubleTimesInteger_hh

#include "TsVParameter.hh"

class TsDoubleFromDoubleTimesInteger: public TsVParameter
{
public:
	TsDoubleFromDoubleTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit);

	~TsDoubleFromDoubleTimesInteger();

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
