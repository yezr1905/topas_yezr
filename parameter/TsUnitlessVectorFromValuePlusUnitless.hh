#ifndef TsUnitlessVectorFromValuePlusUnitless_hh
#define TsUnitlessVectorFromValuePlusUnitless_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValuePlusUnitless: public TsVParameter
{
public:
	TsUnitlessVectorFromValuePlusUnitless(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValuePlusUnitless();

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
