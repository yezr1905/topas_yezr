#ifndef TsMultiWireChamber_hh
#define TsMultiWireChamber_hh

#include "TsVGeometryComponent.hh"

class TsMultiWireChamber : public TsVGeometryComponent
{
public:
	TsMultiWireChamber(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
					   TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsMultiWireChamber();

	G4VPhysicalVolume* Construct();
};

#endif
