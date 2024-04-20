#ifndef TsUnitlessFromIntegerPlusValue_hh
#define TsUnitlessFromIntegerPlusValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerPlusValue: public TsVParameter
{
public:
	TsUnitlessFromIntegerPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsUnitlessFromIntegerPlusValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
