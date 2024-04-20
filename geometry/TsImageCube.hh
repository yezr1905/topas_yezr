#ifndef TsImageCube_hh
#define TsImageCube_hh

#include "TsVPatient.hh"

class TsImageCube :  public TsVPatient
{
public:
	TsImageCube(TsParameterManager* pM, TsMaterialManager* mM,
			  TsGeometryManager* gM, TsVGeometryComponent* parentComponent,
			  G4VPhysicalVolume* parentVolume, G4String& name);
	~TsImageCube();

	void UpdateForSpecificParameterChange(G4String parameter);
	void ReadImage();
};
#endif
