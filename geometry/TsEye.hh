#ifndef TsEye_hh
#define TsEye_hh

#include "TsVGeometryComponent.hh"

class TsEye : public TsVGeometryComponent
{    
public:
	TsEye(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~ TsEye();
	
	G4VPhysicalVolume* Construct();
};

#endif
