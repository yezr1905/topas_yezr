#ifndef TsModularPhysicsList_hh
#define TsModularPhysicsList_hh

#include "G4VModularPhysicsList.hh"
#include "G4VPhysicsConstructor.hh"

#include "TsTopasConfig.hh"

#ifdef TOPAS_MT
#include "G4Cache.hh"
#endif

#include <vector>

class TsParameterManager;
//class TsExtensionManager;
class TsGeometryManager;
class TsPhysicsManager;
class TsVarianceManager;
class TsGeometrySampler;

class G4GeometrySampler;

//Utility class for wrapping
class VPhysicsCreator{
public:
	virtual G4VPhysicsConstructor* operator()() =0;
};

template<class T> class Creator : public VPhysicsCreator{
private:
	T* physics;
public:
	Creator() {physics = 0;}
	virtual ~Creator() {if (!physics) delete physics;}
	G4VPhysicsConstructor* operator()() { return physics = new T; }
};


class TsModularPhysicsList : public G4VModularPhysicsList
{
public:
	//TsModularPhysicsList(TsParameterManager* pM, TsExtensionManager* eM, TsGeometryManager* gM, TsVarianceManager* vM, G4String name);
	TsModularPhysicsList(TsParameterManager* pM, TsGeometryManager* gM, TsVarianceManager* vM, G4String name);
	virtual ~TsModularPhysicsList();

	void AddModule(const G4String& name);

	void AddBiasing(std::vector<G4GeometrySampler*> gs) {fGeomSamplers = gs;};
	void AddBiasing(std::vector<TsGeometrySampler*> pgs) {fProtonGeomSamplers = pgs;};

private:
	void ConstructProcess();
	void ConstructParticle();
	void ActiveG4DNAPerRegion(G4String moduleName);
	void ActiveG4EmModelPerRegion(G4String moduleName);
	void AddTransportationAndParallelScoring();
	void SetUpParallelWorldProcess(G4String worldName, G4bool useLMG);
	void SetCuts();
	G4String GetFullParmName(const char* parmName);

	TsParameterManager* fPm;
	//TsExtensionManager* fEm;
	TsGeometryManager*	fGm;
	TsVarianceManager* fVm;

	G4String fName;
	G4int fNumberBuilt;
	G4bool fTransportationOnly;

	std::vector<G4GeometrySampler*> fGeomSamplers;
	std::vector<TsGeometrySampler*> fProtonGeomSamplers;

	std::map<G4String, VPhysicsCreator*> fPhysicsTable;

protected:
	void AddBiasingProcess();

	void SetEmParameters();
};
#endif
