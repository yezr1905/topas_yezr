#ifndef TsIntegerFromValueMinusInteger_hh
#define TsIntegerFromValueMinusInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromValueMinusInteger: public TsVParameter
{
public:
	TsIntegerFromValueMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsIntegerFromValueMinusInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
