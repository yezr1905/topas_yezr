#ifndef TsStringFromIntegerPlusInteger_hh
#define TsStringFromIntegerPlusInteger_hh

#include "TsVParameter.hh"

class TsStringFromIntegerPlusInteger: public TsVParameter
{
public:
	TsStringFromIntegerPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsStringFromIntegerPlusInteger();

	G4String GetType();

	G4String GetStringValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
