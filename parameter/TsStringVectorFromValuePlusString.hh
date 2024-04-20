#ifndef TsStringVectorFromValuePlusString_hh
#define TsStringVectorFromValuePlusString_hh

#include "TsVParameter.hh"

class TsStringVectorFromValuePlusString: public TsVParameter
{
public:
	TsStringVectorFromValuePlusString(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsStringVectorFromValuePlusString();

	G4String GetType();

	G4int GetVectorLength();

	G4String* GetStringVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4String* fValues;
	G4String* fValuesIfParameterNames;
	G4String fNameOfOtherParameter;
};

#endif
