#ifndef TsEyePlaque_hh
#define TsEyePlaque_hh

#include "TsVGeometryComponent.hh"

class TsEyePlaque : public TsVGeometryComponent
{    
public:
	TsEyePlaque(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsEyePlaque();
	
	G4VPhysicalVolume* Construct();
};

#endif
