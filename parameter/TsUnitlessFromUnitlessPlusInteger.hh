#ifndef TsUnitlessFromUnitlessPlusInteger_hh
#define TsUnitlessFromUnitlessPlusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessPlusInteger: public TsVParameter
{
public:
	TsUnitlessFromUnitlessPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromUnitlessPlusInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
