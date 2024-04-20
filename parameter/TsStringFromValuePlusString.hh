#ifndef TsStringFromValuePlusString_hh
#define TsStringFromValuePlusString_hh

#include "TsVParameter.hh"

class TsStringFromValuePlusString: public TsVParameter
{
public:
	TsStringFromValuePlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsStringFromValuePlusString();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fValue;
	G4String fNameOfOtherParameter;
};

#endif
