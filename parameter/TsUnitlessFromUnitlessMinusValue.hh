#ifndef TsUnitlessFromUnitlessMinusValue_hh
#define TsUnitlessFromUnitlessMinusValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessMinusValue: public TsVParameter
{
public:
	TsUnitlessFromUnitlessMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsUnitlessFromUnitlessMinusValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
