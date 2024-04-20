#ifndef TsDoubleFromTimeFeatureStep_hh
#define TsDoubleFromTimeFeatureStep_hh

#include "TsVParameter.hh"

#include <map>

class TsDoubleFromTimeFeatureStep : public TsVParameter
{
public:
	TsDoubleFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter, G4int nValues, G4String* values ,const G4String& unit);
	~TsDoubleFromTimeFeatureStep();

	G4bool ValueHasChanged();
	void InitializeTimeFeatureValue();

	G4String GetType();
	G4String GetUnit();
	G4double GetDoubleValue();
	G4String GetHTMLValue();

private:
	G4String fUnit;
	G4String fNameOfBaseParameter;
	G4double fLatestUpdatedTime;
	G4double fCurrentValue;

	G4double* fValues;
	G4String* fValuesIfParameterNames;
	std::map<G4double, G4int>* fTimes;
	G4double fRange;
};

#endif
