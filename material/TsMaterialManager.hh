#ifndef TsMaterialManager_hh
#define TsMaterialManager_hh

#include "globals.hh"
#include <map>
#include <vector>

class TsParameterManager;

class G4NistManager;
class G4Element;
class G4Material;
class G4MaterialPropertiesTable;

class TsMaterialManager
{
public:
	TsMaterialManager(TsParameterManager* pm);
	~TsMaterialManager();

	G4Material* GetMaterial(G4String name);
	G4Material* GetMaterial(const char* name);

	G4String GetDefaultMaterialColor(G4String name);
	G4String GetDefaultMaterialColor(const char* name);

	// User classes should not access any methods or data beyond this point.
	void FillMaterialPropertiesTable(G4MaterialPropertiesTable* propertiesTable, G4String prefix);

	std::vector<G4String> GetMaterialNames();

private:
	G4Element* GetElement(G4String name);

	void SetConstantProperty(G4MaterialPropertiesTable* propertiesTable, G4String materialName, G4String propertyName);
	void SetVectorProperty(G4MaterialPropertiesTable* propertiesTable, G4String materialName, G4String propertyName, G4bool applySpline);

	G4String GetFullIsotopeParmName(G4String name, const char* suffix);
	G4String GetFullElementParmName(G4String name, const char* suffix);
	G4String GetFullMaterialParmName(G4String name, const char* suffix);

	void Quit(const G4String& name, const char* message);
	void Quit(const G4String& name, const G4String& message);

	TsParameterManager* fPm;
	G4int fVerbosity;
	G4bool fSetOpticalPropertiesForPatientMaterials;
	G4NistManager* fNistManager;
	std::map<G4String,G4Element*>* fElementMap;
	std::map<G4String,G4Material*>* fMaterialMap;
};

#endif
