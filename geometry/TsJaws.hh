#ifndef TsJaws_hh
#define TsJaws_hh

#include "TsVGeometryComponent.hh"

class TsJaws : public TsVGeometryComponent
{    
public:
	TsJaws(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsJaws();

	G4VPhysicalVolume* Construct();
};
#endif
