#ifndef TsDivergingMLC_hh
#define TsDivergingMLC_hh

#include "TsVGeometryComponent.hh"

class TsDivergingMLC: public TsVGeometryComponent
{
public:
	TsDivergingMLC(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsDivergingMLC();

	G4VPhysicalVolume* Construct();
	void UpdateForSpecificParameterChange(G4String parameter);

private:
	 G4double  fLeafHalfLength;
	 G4double  fMaximumLeafOpen;
	 G4double* fNegFieldSettings;
	 G4double* fPosFieldSettings;
	 G4int fNLeavesPerSide;
	 std::vector<G4VPhysicalVolume*> fXPosLeaves;
	 std::vector<G4VPhysicalVolume*> fXNegLeaves;
};
#endif
