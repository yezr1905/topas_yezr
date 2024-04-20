#ifndef TsStringFromValue_hh
#define TsStringFromValue_hh

#include "TsVParameter.hh"

class TsStringFromValue: public TsVParameter
{
public:
	TsStringFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value);

	~TsStringFromValue();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fValue;
};

#endif
