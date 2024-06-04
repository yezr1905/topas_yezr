#ifndef TsModularPhysicsList_hh
#define TsModularPhysicsList_hh

#include "G4VModularPhysicsList.hh"

#include "TsTopasConfig.hh"

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
	virtual G4VPhysicsConstructor* operator()() = 0;
	virtual ~VPhysicsCreator() = default;

	G4String GetPhysicsName()
	{
        const G4VPhysicsConstructor* phys = this->operator()();
		G4String name = phys->GetPhysicsName();
		delete phys;
		return name;
	}
};

template <class T> class Creator;
template <class T> class CreatorWithPm;

class TsModularPhysicsList : public G4VModularPhysicsList
{
public:
	//TsModularPhysicsList(TsParameterManager* pM, TsExtensionManager* eM, TsGeometryManager* gM, TsVarianceManager* vM, G4String name);
	TsModularPhysicsList(TsParameterManager* pM, TsGeometryManager* gM, TsVarianceManager* vM, G4String name);
	~TsModularPhysicsList() override = default;

	void AddModule(const G4String& name);

	void AddBiasing(std::vector<G4GeometrySampler*> gs) { fGeomSamplers = gs; }
	void AddBiasing(std::vector<TsGeometrySampler*> pgs) { fProtonGeomSamplers = pgs; }

private:
	void ConstructProcess() override;
	void ConstructParticle() override;
	void ActiveG4DNAPerRegion(G4String moduleName);
	void ActiveG4EmModelPerRegion(G4String moduleName);
	void AddTransportationAndParallelScoring();
	void SetUpParallelWorldProcess(G4String worldName, G4bool useLMG);
	void SetCuts() override;
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

	std::map<G4String, VPhysicsCreator*>::const_iterator LocatePhysicsModel(G4String model, G4bool allow_extensions = true);

private:
	G4bool IsPhysicsRegistered(const std::vector<G4VPhysicsConstructor*>* const, G4VPhysicsConstructor*) const;
};

// Inline methods and templates
#include "TsModularPhysicsList.icc"

#endif
