#ifndef TsBooleanFromTimeFeatureStep_hh
#define TsBooleanFromTimeFeatureStep_hh

#include "TsVParameter.hh"

#include <map>

class TsBooleanFromTimeFeatureStep : public TsVParameter
{
public:
	TsBooleanFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter, G4int nValues, G4String* values);
	~TsBooleanFromTimeFeatureStep();

	void InitializeTimeFeatureValue();
	G4bool ValueHasChanged();

	G4String GetType();
	G4String GetHTMLValue();
	G4bool GetBooleanValue();

private:
	G4String fNameOfBaseParameter;
	G4double fLatestUpdatedTime;
	G4bool fCurrentValue;

	G4bool* fValues;
	G4String* fValuesIfParameterNames;
	std::map<G4double, G4int>* fTimes;
	G4double fRange;
};

#endif
