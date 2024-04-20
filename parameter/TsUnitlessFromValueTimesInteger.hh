#ifndef TsUnitlessFromValueTimesInteger_hh
#define TsUnitlessFromValueTimesInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromValueTimesInteger: public TsVParameter
{
public:
	TsUnitlessFromValueTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessFromValueTimesInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
