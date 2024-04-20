#ifndef TsUnitlessFromUnitlessTimesValue_hh
#define TsUnitlessFromUnitlessTimesValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessTimesValue: public TsVParameter
{
public:
	TsUnitlessFromUnitlessTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsUnitlessFromUnitlessTimesValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
