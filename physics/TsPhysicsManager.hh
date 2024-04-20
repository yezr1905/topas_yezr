#ifndef TsPhysicsManager_hh
#define TsPhysicsManager_hh

#include "globals.hh"
#include <vector>

class TsParameterManager;
//class TsExtensionManager;
class TsGeometryManager;
class TsGeometrySampler;
class TsVarianceManager;

class G4VUserPhysicsList;
class G4GeometrySampler;

class TsPhysicsManager
{
public:
	//TsPhysicsManager(TsParameterManager* pM, TsExtensionManager* eM, TsGeometryManager* gM);
	TsPhysicsManager(TsParameterManager* pM, TsGeometryManager* gM);
	~TsPhysicsManager();

	G4VUserPhysicsList* GetPhysicsList();
	void AddBiasing(std::vector<G4GeometrySampler*> mgs) {fGeomSamplers = mgs;};
	void AddBiasing(std::vector<TsGeometrySampler*> pmgs) {fProtonGeomSamplers = pmgs;};
	void SetVarianceManager(TsVarianceManager* vM);
	
private:
	TsParameterManager* fPm;
	//TsExtensionManager* fEm;
	TsGeometryManager*	fGm;
	TsVarianceManager*  fVm;

	G4String fPhysicsListName;

	void SetEmParameters();

	G4String GetFullParmName(const char* parmName);

	std::vector<G4GeometrySampler*> fGeomSamplers;
	std::vector<TsGeometrySampler*> fProtonGeomSamplers;
};
#endif

