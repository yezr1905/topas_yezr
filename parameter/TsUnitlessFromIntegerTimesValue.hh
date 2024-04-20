#ifndef TsUnitlessFromIntegerTimesValue_hh
#define TsUnitlessFromIntegerTimesValue_hh

#include "TsVParameter.hh"

class TsUnitlessFromIntegerTimesValue: public TsVParameter
{
public:
	TsUnitlessFromIntegerTimesValue(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 const G4String& nameOfOtherParameter, const G4String& value);

	~TsUnitlessFromIntegerTimesValue();

	G4String GetType();

	G4double GetUnitlessValue();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
