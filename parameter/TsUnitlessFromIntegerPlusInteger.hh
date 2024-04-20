#ifndef TsUnitlessFromIntegerPlusInteger_hh
#define TsUnitlessFromIntegerPlusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerPlusInteger: public TsVParameter
{
public:
	TsUnitlessFromIntegerPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromIntegerPlusInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
