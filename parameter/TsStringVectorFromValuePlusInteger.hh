#ifndef TsStringVectorFromValuePlusInteger_hh
#define TsStringVectorFromValuePlusInteger_hh

#include "TsVParameter.hh"

class TsStringVectorFromValuePlusInteger: public TsVParameter
{
public:
	TsStringVectorFromValuePlusInteger(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsStringVectorFromValuePlusInteger();

	G4String GetType();

	G4int GetVectorLength();

	G4String* GetStringVector();

	G4String GetHTMLValue();

private:
	G4int fLength;
	G4String* fValues;
	G4String fNameOfOtherParameter;
	G4String* fValuesIfParameterNames;
};

#endif
