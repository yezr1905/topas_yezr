#ifndef TsUnitlessVectorFromValueTimesUnitless_hh
#define TsUnitlessVectorFromValueTimesUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValueTimesUnitless: public TsVParameter
{
public:
	TsUnitlessVectorFromValueTimesUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValueTimesUnitless();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4double* fValues;
	G4String* fValuesIfParameterNames;
	G4String fNameOfOtherParameter;
};

#endif
