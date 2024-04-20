#ifndef TsAperture_hh
#define TsAperture_hh

#include "TsVGeometryComponent.hh"

class TsAperture : public TsVGeometryComponent
{
public:
	TsAperture(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
			   TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsAperture();

	G4VPhysicalVolume* Construct();
};
#endif
