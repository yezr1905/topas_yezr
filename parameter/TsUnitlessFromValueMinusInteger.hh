#ifndef TsUnitlessFromValueMinusInteger_hh
#define TsUnitlessFromValueMinusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromValueMinusInteger: public TsVParameter
{
public:
	TsUnitlessFromValueMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessFromValueMinusInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
