#ifndef TsUnitlessFromTimeFeature_hh
#define TsUnitlessFromTimeFeature_hh

#include "TsVParameter.hh"
#include "TsVTimeFunction.hh"

class TsUnitlessFromTimeFeature : public TsVParameter
{
public:
	TsUnitlessFromTimeFeature(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
							const G4String& nameOfBaseParameter);
	~TsUnitlessFromTimeFeature();

	void InitializeTimeFeatureValue();
	G4bool ValueHasChanged();

	G4String GetType();
	G4double GetUnitlessValue();
	G4String GetHTMLValue();

private:
	TsVTimeFunction* fFunction;
	G4String fNameOfBaseParameter;

	G4double fLatestUpdatedTime;
	G4double fCurrentValue;
	G4double fRange;
};

#endif
