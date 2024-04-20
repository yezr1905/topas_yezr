#ifndef TsIntegerFromIntegerPlusInteger_hh
#define TsIntegerFromIntegerPlusInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerPlusInteger: public TsVParameter
{
public:
	TsIntegerFromIntegerPlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsIntegerFromIntegerPlusInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
