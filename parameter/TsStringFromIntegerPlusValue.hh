#ifndef TsStringFromIntegerPlusValue_hh
#define TsStringFromIntegerPlusValue_hh

#include "TsVParameter.hh"

class TsStringFromIntegerPlusValue: public TsVParameter
{
public:
	TsStringFromIntegerPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsStringFromIntegerPlusValue();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fValue;
	G4String fNameOfOtherParameter;
};

#endif
