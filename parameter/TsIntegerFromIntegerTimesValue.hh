#ifndef TsIntegerFromIntegerTimesValue_hh
#define TsIntegerFromIntegerTimesValue_hh

#include "TsVParameter.hh"

class TsIntegerFromIntegerTimesValue: public TsVParameter
{
public:
	TsIntegerFromIntegerTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsIntegerFromIntegerTimesValue();

	G4String GetType();

	G4int GetIntegerValue();

	G4String GetHTMLValue();

private:
	G4int fValue;
	G4String fNameOfOtherParameter;
};

#endif
