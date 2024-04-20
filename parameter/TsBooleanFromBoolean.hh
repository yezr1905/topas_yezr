#ifndef TsBooleanFromBoolean_hh
#define TsBooleanFromBoolean_hh

#include "TsVParameter.hh"

class TsBooleanFromBoolean : public TsVParameter
{
public:
	TsBooleanFromBoolean(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter);

	~TsBooleanFromBoolean();

	G4String GetType();

	G4bool GetBooleanValue();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
