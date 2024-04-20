#ifndef TsUnitlessFromUnitless_hh
#define TsUnitlessFromUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitless: public TsVParameter
{
public:
	TsUnitlessFromUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter);

	~TsUnitlessFromUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
