#ifndef TsUnitlessFromIntegerMinusValue_hh
#define TsUnitlessFromIntegerMinusValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerMinusValue: public TsVParameter
{
public:
	TsUnitlessFromIntegerMinusValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsUnitlessFromIntegerMinusValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
