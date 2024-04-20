#ifndef TsCylinder_hh
#define TsCylinder_hh

#include "TsVGeometryComponent.hh"

class TsCylinder : public TsVGeometryComponent
{
public:
	TsCylinder(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsCylinder();

	G4VPhysicalVolume* Construct();

	// Methods used by scorers
	G4int GetIndex(G4Step* aStep);
	G4int GetIndex(G4int iR, G4int iPhi, G4int iZ);
	G4int GetBin(G4int index, G4int iBin);
	SurfaceType GetSurfaceID(G4String surfaceName);
	G4bool IsOnBoundary(G4ThreeVector localpos, G4VSolid* solid, SurfaceType surfaceID);
	G4double GetAreaOfSelectedSurface(G4VSolid* solid, SurfaceType surfaceID, G4int i, G4int j, G4int k);

	// Methods used by parameterization
	G4Material* ComputeMaterial(const G4int repNo, G4VPhysicalVolume* pvol, const G4VTouchable* parent);
	void ComputeTransformation(const G4int, G4VPhysicalVolume* pvol) const;
	void ComputeDimensions(G4Tubs&, const G4int, const G4VPhysicalVolume*) const;
	void ComputeDimensions(G4Sphere&, const G4int, const G4VPhysicalVolume*) const{};

	static void CreateDefaults(TsParameterManager* pM, G4String& childName, G4String& parentName);

private:
	G4double fTotalRMin;

	std::vector<G4RotationMatrix*> fPhiDivisionRotations;
};

#endif
