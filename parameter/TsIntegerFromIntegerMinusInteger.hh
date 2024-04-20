#ifndef TsIntegerFromIntegerMinusInteger_hh
#define TsIntegerFromIntegerMinusInteger_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerMinusInteger: public TsVParameter
{
public:
	TsIntegerFromIntegerMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsIntegerFromIntegerMinusInteger();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
