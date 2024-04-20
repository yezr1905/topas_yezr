#ifndef TsDoubleFromDouble_hh
#define TsDoubleFromDouble_hh

#include "TsVParameter.hh"

class TsDoubleFromDouble: public TsVParameter
{
public:
	TsDoubleFromDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
					   const G4String& nameOfOtherParameter, const G4String& unit);

	~TsDoubleFromDouble();

	void CheckRelativeParameterConsistency();

	G4String GetType();

	G4String GetUnit();

	G4double GetDoubleValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
	G4String fUnit;
};

#endif
