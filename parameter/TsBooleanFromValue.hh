#ifndef TsBooleanFromValue_hh
#define TsBooleanFromValue_hh

#include "TsVParameter.hh"

class TsBooleanFromValue: public TsVParameter
{
public:
	TsBooleanFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value);

	~TsBooleanFromValue();

	G4String GetType();

	G4bool GetBooleanValue();

	G4String GetHTMLValue();

private:
	G4bool fValue;
};

#endif
