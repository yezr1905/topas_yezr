#ifndef TsUnitlessFromValueMinusUnitless_hh
#define TsUnitlessFromValueMinusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromValueMinusUnitless: public TsVParameter
{
public:
	TsUnitlessFromValueMinusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessFromValueMinusUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
