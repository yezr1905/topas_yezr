#ifndef TsUnitlessFromIntegerPlusUnitless_hh
#define TsUnitlessFromIntegerPlusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerPlusUnitless: public TsVParameter
{
public:
	TsUnitlessFromIntegerPlusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromIntegerPlusUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
