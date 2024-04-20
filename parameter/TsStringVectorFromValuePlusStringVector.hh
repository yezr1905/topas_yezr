#ifndef TsStringVectorFromValuePlusStringVector_hh
#define TsStringVectorFromValuePlusStringVector_hh

#include "TsVParameter.hh"

class TsStringVectorFromValuePlusStringVector: public TsVParameter
{
public:
	TsStringVectorFromValuePlusStringVector(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
						 G4int nValues, G4String* values, const G4String& nameOfOtherParameter);

	~TsStringVectorFromValuePlusStringVector();

	void CheckRelativeParameterConsistency();

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
