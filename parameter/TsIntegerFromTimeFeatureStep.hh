#ifndef TsIntegerFromTimeFeatureStep_hh
#define TsIntegerFromTimeFeatureStep_hh

#include "TsVParameter.hh"

#include <map>

class TsIntegerFromTimeFeatureStep : public TsVParameter
{
public:
	TsIntegerFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter, G4int nValues, G4String* values);
	~TsIntegerFromTimeFeatureStep();

	void InitializeTimeFeatureValue();
	G4bool ValueHasChanged();

	G4String GetType();
	G4String GetHTMLValue();
	G4int GetIntegerValue();

private:
	G4String fNameOfBaseParameter;
	G4double fLatestUpdatedTime;
	G4int fCurrentValue;

	G4int* fValues;
	G4String* fValuesIfParameterNames;
	std::map<G4double, G4int>* fTimes;
	G4double fRange;
};

#endif
