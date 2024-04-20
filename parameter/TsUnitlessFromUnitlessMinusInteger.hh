#ifndef TsUnitlessFromUnitlessMinusInteger_hh
#define TsUnitlessFromUnitlessMinusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessMinusInteger: public TsVParameter
{
public:
	TsUnitlessFromUnitlessMinusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromUnitlessMinusInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
