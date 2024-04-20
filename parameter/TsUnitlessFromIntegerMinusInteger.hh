#ifndef TsUnitlessFromIntegerMinusInteger_hh
#define TsUnitlessFromIntegerMinusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerMinusInteger: public TsVParameter
{
public:
	TsUnitlessFromIntegerMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromIntegerMinusInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
