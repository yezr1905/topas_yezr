#ifndef TsBrachyShieldStar_hh
#define TsBrachyShieldStar_hh

#include "TsVGeometryComponent.hh"

class TsBrachyShieldStar : public TsVGeometryComponent
{
public:
	TsBrachyShieldStar(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
			   TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsBrachyShieldStar();

	G4VPhysicalVolume* Construct();
};
#endif
