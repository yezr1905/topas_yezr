#ifndef TsStringVectorFromStringVector_hh
#define TsStringVectorFromStringVector_hh

#include "TsVParameter.hh"

class TsStringVectorFromStringVector: public TsVParameter
{
public:
	TsStringVectorFromStringVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
								     const G4String& nameOfOtherParameter);

	~TsStringVectorFromStringVector();

	G4String GetType();

	G4int GetVectorLength();

	G4String* GetStringVector();

	G4String GetHTMLValue();

private:
	G4String fNameOfOtherParameter;
};

#endif
