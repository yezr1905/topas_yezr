#ifndef TsUnitlessFromUnitlessMinusUnitless_hh
#define TsUnitlessFromUnitlessMinusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessMinusUnitless: public TsVParameter
{
public:
	TsUnitlessFromUnitlessMinusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromUnitlessMinusUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
