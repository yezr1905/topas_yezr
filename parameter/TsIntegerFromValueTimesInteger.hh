#ifndef TsIntegerFromValueTimesInteger_hh
#define TsIntegerFromValueTimesInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromValueTimesInteger: public TsVParameter
{
public:
	TsIntegerFromValueTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsIntegerFromValueTimesInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
