#ifndef TsIntegerFromValue_hh
#define TsIntegerFromValue_hh

#include "TsVParameter.hh"

class TsIntegerFromValue: public TsVParameter
{
public:
	TsIntegerFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value);

	~TsIntegerFromValue();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
};

#endif
