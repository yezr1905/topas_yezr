#ifndef TsStringFromIntegerPlusString_hh
#define TsStringFromIntegerPlusString_hh

#include "TsVParameter.hh"

class TsStringFromIntegerPlusString: public TsVParameter
{
public:
	TsStringFromIntegerPlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsStringFromIntegerPlusString();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
