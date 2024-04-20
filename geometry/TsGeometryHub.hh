#ifndef TsGeometryHub_hh
#define TsGeometryHub_hh

#include "globals.hh"

class TsParameterManager;
//class TsExtensionManager;
class TsMaterialManager;
class TsGeometryManager;

class TsVGeometryComponent;
class G4VPhysicalVolume;

class TsGeometryHub
{
public:
	TsGeometryHub(TsParameterManager* pM);
	~TsGeometryHub();

	TsVGeometryComponent* InstantiateComponent(TsParameterManager* pM,
											   TsMaterialManager* mM, TsGeometryManager* gM, TsVGeometryComponent* pgc,
											   G4VPhysicalVolume* pv, G4String childCompType, G4String childName);

	static void AddComponentFromGUI(TsParameterManager* pM, TsGeometryManager* gM,
							 G4String& childName, G4String& parentName, G4String& typeName, G4String& fieldName);
};
#endif
