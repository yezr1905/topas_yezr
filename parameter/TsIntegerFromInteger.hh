#ifndef TsIntegerFromInteger_hh
#define TsIntegerFromInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromInteger: public TsVParameter
{
public:
	TsIntegerFromInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter);

	~TsIntegerFromInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
