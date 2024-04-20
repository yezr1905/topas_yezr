#ifndef TsStringFromString_hh
#define TsStringFromString_hh

#include "TsVParameter.hh"

class TsStringFromString: public TsVParameter
{
public:
	TsStringFromString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter);

	~TsStringFromString();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
