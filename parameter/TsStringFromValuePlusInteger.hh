#ifndef TsStringFromValuePlusInteger_hh
#define TsStringFromValuePlusInteger_hh

#include "TsVParameter.hh"

class TsStringFromValuePlusInteger: public TsVParameter
{
public:
	TsStringFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsStringFromValuePlusInteger();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fValue;
	G4String fNameOfOtherParameter;
};

#endif
