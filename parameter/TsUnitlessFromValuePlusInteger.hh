#ifndef TsUnitlessFromValuePlusInteger_hh
#define TsUnitlessFromValuePlusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromValuePlusInteger: public TsVParameter
{
public:
	TsUnitlessFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessFromValuePlusInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
