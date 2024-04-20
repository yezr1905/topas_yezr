#ifndef TsDoubleFromDoublePlusValue_hh
#define TsDoubleFromDoublePlusValue_hh

#include "TsVParameter.hh"

class TsDoubleFromDoublePlusValue: public TsVParameter
{
public:
	TsDoubleFromDoublePlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								const G4String& nameOfOtherParameter, const G4String& value, const G4String& unit);

	~TsDoubleFromDoublePlusValue();

	void CheckRelativeParameterConsistency();

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
