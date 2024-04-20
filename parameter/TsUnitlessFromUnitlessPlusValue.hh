#ifndef TsUnitlessFromUnitlessPlusValue_hh
#define TsUnitlessFromUnitlessPlusValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessPlusValue: public TsVParameter
{
public:
	TsUnitlessFromUnitlessPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsUnitlessFromUnitlessPlusValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
