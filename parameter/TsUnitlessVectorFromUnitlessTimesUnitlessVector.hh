#ifndef TsUnitlessVectorFromUnitlessTimesUnitlessVector_hh
#define TsUnitlessVectorFromUnitlessTimesUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromUnitlessTimesUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromUnitlessTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& fNameOfOtherParameter1, const G4String& fNameOfOtherParameter2);

	~TsUnitlessVectorFromUnitlessTimesUnitlessVector();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
