#ifndef TsStringFromInteger_hh
#define TsStringFromInteger_hh

#include "TsVParameter.hh"

class TsStringFromInteger: public TsVParameter
{
public:
	TsStringFromInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						const G4String& nameOfOtherParameter);

	~TsStringFromInteger();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
