#ifndef TsDoubleFromTimeFeature_hh
#define TsDoubleFromTimeFeature_hh

#include "TsVParameter.hh"
#include "TsVTimeFunction.hh"

class TsDoubleFromTimeFeature : public TsVParameter
{
public:
	TsDoubleFromTimeFeature(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter, const G4String& unit);
	~TsDoubleFromTimeFeature();

	void InitializeTimeFeatureValue();
	G4bool ValueHasChanged();

	G4String GetType();
	G4String GetUnit();
	G4double GetDoubleValue();
	G4String GetHTMLValue();

private:
	TsVTimeFunction* fFunction;
	G4String fUnit;
	G4String fNameOfBaseParameter;

	G4double fLatestUpdatedTime;
	G4double fCurrentValue;
	G4double fRange;
};

#endif
