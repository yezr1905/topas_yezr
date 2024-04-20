#ifndef TsStringFromStringPlusValue_hh
#define TsStringFromStringPlusValue_hh

#include "TsVParameter.hh"

class TsStringFromStringPlusValue: public TsVParameter
{
public:
	TsStringFromStringPlusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsStringFromStringPlusValue();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fValue;
	G4String fNameOfOtherParameter;
};

#endif
