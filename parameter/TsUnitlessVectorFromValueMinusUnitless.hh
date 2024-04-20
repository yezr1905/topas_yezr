#ifndef TsUnitlessVectorFromValueMinusUnitless_hh
#define TsUnitlessVectorFromValueMinusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValueMinusUnitless: public TsVParameter
{
public:
	TsUnitlessVectorFromValueMinusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValueMinusUnitless();

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
