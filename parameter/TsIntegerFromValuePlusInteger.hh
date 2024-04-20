#ifndef TsIntegerFromValuePlusInteger_hh
#define TsIntegerFromValuePlusInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromValuePlusInteger: public TsVParameter
{
public:
	TsIntegerFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsIntegerFromValuePlusInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
