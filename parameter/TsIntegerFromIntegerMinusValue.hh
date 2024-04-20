#ifndef TsIntegerFromIntegerMinusValue_hh
#define TsIntegerFromIntegerMinusValue_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerMinusValue: public TsVParameter
{
public:
	TsIntegerFromIntegerMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsIntegerFromIntegerMinusValue();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
