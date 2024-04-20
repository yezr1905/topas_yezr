#ifndef TsIntegerFromIntegerPlusValue_hh
#define TsIntegerFromIntegerPlusValue_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerPlusValue: public TsVParameter
{
public:
	TsIntegerFromIntegerPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsIntegerFromIntegerPlusValue();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
