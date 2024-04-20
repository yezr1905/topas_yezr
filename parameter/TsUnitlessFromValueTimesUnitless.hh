#ifndef TsUnitlessFromValueTimesUnitless_hh
#define TsUnitlessFromValueTimesUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromValueTimesUnitless: public TsVParameter
{
public:
	TsUnitlessFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessFromValueTimesUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
