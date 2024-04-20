#ifndef TsStringFromStringPlusInteger_hh
#define TsStringFromStringPlusInteger_hh

#include "TsVParameter.hh"

class TsStringFromStringPlusInteger: public TsVParameter
{
public:
	TsStringFromStringPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsStringFromStringPlusInteger();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
