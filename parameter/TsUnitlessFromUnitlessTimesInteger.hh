#ifndef TsUnitlessFromUnitlessTimesInteger_hh
#define TsUnitlessFromUnitlessTimesInteger_hh

#include "TsVParameter.hh"

class TsUnitlessFromUnitlessTimesInteger: public TsVParameter
{
public:
	TsUnitlessFromUnitlessTimesInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsUnitlessFromUnitlessTimesInteger();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
