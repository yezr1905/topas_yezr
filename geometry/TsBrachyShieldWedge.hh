#ifndef TsBrachyShieldWedge_hh
#define TsBrachyShieldWedge_hh

#include "TsVGeometryComponent.hh"

class TsBrachyShieldWedge : public TsVGeometryComponent
{
public:
	TsBrachyShieldWedge(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
			   TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsBrachyShieldWedge();

	G4VPhysicalVolume* Construct();
};
#endif
