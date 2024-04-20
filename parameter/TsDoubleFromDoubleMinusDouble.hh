#ifndef TsDoubleFromDoubleMinusDouble_hh
#define TsDoubleFromDoubleMinusDouble_hh

#include "TsVParameter.hh"

class TsDoubleFromDoubleMinusDouble: public TsVParameter
{
public:
	TsDoubleFromDoubleMinusDouble(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2, const G4String& unit);

	~TsDoubleFromDoubleMinusDouble();

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
