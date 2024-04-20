#ifndef TsUnitlessVectorFromUnitlessVector_hh
#define TsUnitlessVectorFromUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								     const G4String& nameOfOtherParameter);

	~TsUnitlessVectorFromUnitlessVector();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
