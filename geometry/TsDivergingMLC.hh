#ifndef TsDivergingMLC_hh
#define TsDivergingMLC_hh

#include "TsVGeometryComponent.hh"

class G4GenericTrap;

class TsDivergingMLC : public TsVGeometryComponent
{
public:
	TsDivergingMLC(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsDivergingMLC();

	G4VPhysicalVolume* Construct();
	void UpdateForSpecificParameterChange(G4String parameter);

private:
	std::pair<G4GenericTrap*,G4GenericTrap*> ConstructLeafPair(G4int,G4double,G4double,G4double,G4double,G4double,G4bool);

private:
	// Leaf Position Variables
	G4double  fSUSD;
	G4double  fSAD;
	G4double  fMagnification;
	G4double  fHalfTotalMLCWidth;
	G4double  fLeafThickness;
	G4double  fLeafHalfLength;
	G4double  fMaximumLeafOpen;
	G4double* fXPlusLeavesOpen;
	G4double* fXMinusLeavesOpen;
	G4int fNbOfLeavesPerSide;

	G4bool fIsXMLC;

	// Generic Volume storage
	std::vector<G4GenericTrap*> fGenericTrapXPlusLeaves;
	std::vector<G4GenericTrap*> fGenericTrapXMinusLeaves;

	// Logic Volume storage
	std::vector<G4LogicalVolume*> fLogicXPlusLeaves;
	std::vector<G4LogicalVolume*> fLogicXMinusLeaves;

	// Physical Volume storage
	std::vector<G4VPhysicalVolume*> fPhysicalXPlusLeaves;
	std::vector<G4VPhysicalVolume*> fPhysicalXMinusLeaves;
};

#endif
