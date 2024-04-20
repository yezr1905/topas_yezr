#ifndef TsGenericComponent_hh
#define TsGenericComponent_hh

#include "TsVGeometryComponent.hh"

class TsGenericComponent : public TsVGeometryComponent
{
public:
	TsGenericComponent(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
						TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsGenericComponent();

	G4VPhysicalVolume* Construct();

	static G4bool CreateDefaults(TsParameterManager* pM, G4String& childName, G4String& parentName, G4String& childCompType);
private:
	void CheckLengthMatch(G4String parameterName1, G4String parameterName2);
};

#endif
