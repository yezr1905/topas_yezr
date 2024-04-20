#ifndef TsUnitlessFromIntegerMinusUnitless_hh
#define TsUnitlessFromIntegerMinusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerMinusUnitless: public TsVParameter
{
public:
	TsUnitlessFromIntegerMinusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromIntegerMinusUnitless();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
