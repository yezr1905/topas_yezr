#ifndef TsApertureArray_hh
#define TsApertureArray_hh

#include "TsVGeometryComponent.hh"

class TsApertureArray : public TsVGeometryComponent
{
public:
	TsApertureArray(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
			   TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsApertureArray();

	G4VPhysicalVolume* Construct();
};
#endif
