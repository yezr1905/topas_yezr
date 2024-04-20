#ifndef TsUnitlessFromUnitlessPlusUnitless_hh
#define TsUnitlessFromUnitlessPlusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessPlusUnitless: public TsVParameter
{
public:
	TsUnitlessFromUnitlessPlusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromUnitlessPlusUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
