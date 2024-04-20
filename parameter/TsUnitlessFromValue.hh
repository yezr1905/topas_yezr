#ifndef TsUnitlessFromValue_hh
#define TsUnitlessFromValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromValue: public TsVParameter
{
public:
	TsUnitlessFromValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value);

	~TsUnitlessFromValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
};

#endif
