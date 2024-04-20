#ifndef TsMultiLeafCollimator_hh
#define TsMultiLeafCollimator_hh

#include "TsVGeometryComponent.hh"

class TsMultiLeafCollimator : public TsVGeometryComponent
{
public:
	TsMultiLeafCollimator(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsMultiLeafCollimator();

	G4VPhysicalVolume* Construct();
	void UpdateForSpecificParameterChange(G4String parameter);

private:
	 G4double  LeafHalfLength;
	 G4double  MaximumLeafOpen;
	 G4double* XPlusLeavesOpen;
	 G4double* XMinusLeavesOpen;
	 std::vector<G4VPhysicalVolume*> XPlusLeaves;
	 std::vector<G4VPhysicalVolume*> XMinusLeaves;
	 G4int NbOfLeavesPerSide;
};

#endif
