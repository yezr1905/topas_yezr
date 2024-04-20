#ifndef TsRidgeFilter_hh
#define TsRidgeFilter_hh

#include "TsVGeometryComponent.hh"

class TsRidgeFilter : public TsVGeometryComponent {
public:
	TsRidgeFilter(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsRidgeFilter();

	G4VPhysicalVolume* Construct();
};

#endif
