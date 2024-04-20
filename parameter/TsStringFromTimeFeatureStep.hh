#ifndef TsStringFromTimeFeatureStep_hh
#define TsStringFromTimeFeatureStep_hh

#include "TsVParameter.hh"

#include <map>

class TsStringFromTimeFeatureStep : public TsVParameter
{
public:
	TsStringFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter, G4int nValues, G4String* values);
	~TsStringFromTimeFeatureStep();

	void InitializeTimeFeatureValue();
	G4bool ValueHasChanged();

	G4String GetType();
	G4String GetHTMLValue();
	G4String GetStringValue();

private:
	G4String fNameOfBaseParameter;
	G4double fLatestUpdatedTime;
	G4String fCurrentValue;

	G4String* fValues;
	G4String* fValuesIfParameterNames;
	std::map<G4double, G4int>* fTimes;
	G4double fRange;
};

#endif
