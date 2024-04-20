#ifndef TsUnitlessFromValuePlusUnitless_hh
#define TsUnitlessFromValuePlusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromValuePlusUnitless: public TsVParameter
{
public:
	TsUnitlessFromValuePlusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessFromValuePlusUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
