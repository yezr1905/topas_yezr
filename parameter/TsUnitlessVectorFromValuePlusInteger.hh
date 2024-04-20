#ifndef TsUnitlessVectorFromValuePlusInteger_hh
#define TsUnitlessVectorFromValuePlusInteger_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromValuePlusInteger: public TsVParameter
{
public:
	TsUnitlessVectorFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromValuePlusInteger();

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
