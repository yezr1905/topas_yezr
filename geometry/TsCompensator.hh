#ifndef TsCompensator_hh
#define TsCompensator_hh

#include "TsVGeometryComponent.hh"

class TsCompensator : public TsVGeometryComponent
{
public:
	TsCompensator(TsParameterManager* pM,
				  TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsCompensator();

	G4VPhysicalVolume* Construct();

private:
	void BuildAsPolyhedra();
	void BuildAsExtrudedSolid();
	void BuildAsUnionSolid();
	void BuildAsSubtractionSolid();
	std::vector<G4Tubs*> GetDrillHoleCylinders();
	std::vector<G4ThreeVector*> GetDrillHoleLocations();

	G4String fFileName;
	G4double fConversionFactor;
	G4double fMainCylinderThickness;
	G4double fMainCylinderRadius;
	G4double fMainCylinderRadiusSquared;
	G4double fDrillHoleRadius;
	G4VSolid* fMainCylinder;

	G4int fNumRows;
	// One per row
	std::vector<G4double> fXSteps;
	std::vector<G4double> fXStarts;
	std::vector<G4double> fYStarts;
	// per row and per column
	std::vector< std::vector<G4double> > fDepths;
};

#endif
