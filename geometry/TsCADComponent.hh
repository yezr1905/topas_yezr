#ifndef TsCADComponent_hh
#define TsCADComponent_hh

#include "TsVGeometryComponent.hh"

class G4TessellatedSolid;

class TsCADComponent : public TsVGeometryComponent
{
public:
	TsCADComponent(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsCADComponent();

	G4VPhysicalVolume* Construct();
	G4double* fVertex;

	void ReadCADFromPLY();
	void ReadCADFromSTL();
	void ReadCADFromTET();

private:
	G4double fUnits;
	G4String fFileName;
	G4TessellatedSolid* fSolid;
};

#endif
