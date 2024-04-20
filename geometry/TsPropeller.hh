#ifndef TsPropeller_hh
#define TsPropeller_hh

#include "TsVGeometryComponent.hh"

#include "G4VPVParameterisation.hh"

class TsPropeller : public TsVGeometryComponent
{
public:
	TsPropeller(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsPropeller();

	G4VPhysicalVolume* Construct();
};

#endif
