#ifndef TsUnitlessVectorFromScaleTimesUnitlessVector_hh
#define TsUnitlessVectorFromScaleTimesUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromScaleTimesUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromScaleTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& value, const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromScaleTimesUnitlessVector();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4double fValue;
	G4String fNameOfOtherParameter;
};

#endif
