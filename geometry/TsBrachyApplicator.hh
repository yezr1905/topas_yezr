#ifndef TsBrachyApplicator_hh
#define TsBrachyApplicator_hh

#include "TsVGeometryComponent.hh"

class TsBrachyApplicator : public TsVGeometryComponent
{
public:
	TsBrachyApplicator(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
			   TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsBrachyApplicator();

	G4VPhysicalVolume* Construct();
};
#endif
