#ifndef TsBox_hh
#define TsBox_hh

#include "TsVGeometryComponent.hh"

class TsBox : public TsVGeometryComponent
{
public:
	TsBox(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsBox();

	G4VPhysicalVolume* Construct();

	// Methods used by scorers
	G4int GetIndex(G4Step* aStep);
	G4int GetIndex(G4int iX, G4int iY, G4int iZ);
	G4int GetBin(G4int index, G4int iBin);
	SurfaceType GetSurfaceID(G4String surfaceName);
	G4bool IsOnBoundary(G4ThreeVector localpos, G4VSolid* solid, SurfaceType surfaceID);
	G4double GetAreaOfSelectedSurface(G4VSolid* solid, SurfaceType surfaceID, G4int iX, G4int iY, G4int iZ);

	// Methods used by parameterization
	G4Material* ComputeMaterial(const G4int repNo, G4VPhysicalVolume* pvol, const G4VTouchable* parent);
	void ComputeTransformation(const G4int, G4VPhysicalVolume* pvol) const;

	G4Point3D GetTransFirstVoxelCenterRelToComponentCenter() { return fTransFirstVoxelCenterRelToComponentCenter; }

	void SetShowSpecificSlicesX(G4bool*);
	void SetShowSpecificSlicesY(G4bool*);
	void SetShowSpecificSlicesZ(G4bool*);

	static void CreateDefaults(TsParameterManager* pM, G4String& childName, G4String& parentName);
protected:
	void ConstructVoxelStructure();

	G4bool fShowOnlyOutline;
	G4bool fConstructParameterized;
	G4Point3D fTransFirstVoxelCenterRelToComponentCenter;

private:
	G4bool* fShowSpecificSlicesX;
	G4bool* fShowSpecificSlicesY;
	G4bool* fShowSpecificSlicesZ;
};

#endif
