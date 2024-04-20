#ifndef TsUnitlessVectorFromIntegerTimesUnitlessVector_hh
#define TsUnitlessVectorFromIntegerTimesUnitlessVector_hh

#include "TsVParameter.hh"

class TsUnitlessVectorFromIntegerTimesUnitlessVector: public TsVParameter
{
public:
	TsUnitlessVectorFromIntegerTimesUnitlessVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								  const G4String& fNameOfOtherParameter1, const G4String& fNameOfOtherParameter2);

	~TsUnitlessVectorFromIntegerTimesUnitlessVector();

	G4String GetType();

	G4int GetVectorLength();

	G4double* GetUnitlessVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter1;
	G4String fNameOfOtherParameter2;
};

#endif
