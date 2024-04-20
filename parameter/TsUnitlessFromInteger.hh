#ifndef TsUnitlessFromInteger_hh
#define TsUnitlessFromInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromInteger: public TsVParameter
{
public:
	TsUnitlessFromInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter);

	~TsUnitlessFromInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
