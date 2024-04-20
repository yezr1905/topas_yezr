#ifndef TsUnitlessFromTimeFeatureStep_hh
#define TsUnitlessFromTimeFeatureStep_hh

#include "TsVParameter.hh"

#include <map>

class TsUnitlessFromTimeFeatureStep : public TsVParameter
{
public:
	TsUnitlessFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter, G4int nValues, G4String* values);
	~TsUnitlessFromTimeFeatureStep();

	G4bool ValueHasChanged();
	void InitializeTimeFeatureValue();

	G4String GetType();
	G4String GetHTMLValue();
	G4double GetUnitlessValue();

private:
	G4String fNameOfBaseParameter;
	G4double fLatestUpdatedTime;
	G4double fCurrentValue;

	G4double* fValues;
	G4String* fValuesIfParameterNames;
	std::map<G4double, G4int>* fTimes;
	G4double fRange;
};

#endif
