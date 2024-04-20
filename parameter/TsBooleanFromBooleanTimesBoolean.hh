#ifndef TsBooleanFromBooleanTimesBoolean_hh
#define TsBooleanFromBooleanTimesBoolean_hh

#include "TsVParameter.hh"

class TsBooleanFromBooleanTimesBoolean: public TsVParameter
{
public:
	TsBooleanFromBooleanTimesBoolean(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter1, const G4String& nameOfOtherParameter2);

	~TsBooleanFromBooleanTimesBoolean();

	G4String GetType();

	G4bool GetBooleanValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
