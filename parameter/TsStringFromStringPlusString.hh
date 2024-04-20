#ifndef TsStringFromStringPlusString_hh
#define TsStringFromStringPlusString_hh

#include "TsVParameter.hh"

class TsStringFromStringPlusString: public TsVParameter
{
public:
	TsStringFromStringPlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsStringFromStringPlusString();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
