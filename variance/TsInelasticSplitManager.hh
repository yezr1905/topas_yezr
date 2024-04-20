#ifndef TsInelasticSplitManager_hh
#define TsInelasticSplitManager_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;
class G4GenericBiasingPhysics;

class TsInelasticSplitManager : public TsVBiasingProcess
{
public:
	TsInelasticSplitManager(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsInelasticSplitManager();

	void ResolveParameters();
	void Initialize();
	void Clear();
	void SetGenericBiasing(); 
	void AddBiasingProcess() { return; };
	
	G4GenericBiasingPhysics* GetGenericBiasingPhysics();
	G4String GetTypeName() { return fType;};
	
private:
	TsParameterManager* fPm;

	G4String fName;
	G4String fType;
		
	G4int fNbOfParticles;
	G4String* fProcessesToBias;
	G4String* fParticlesToBias;
	std::vector<G4String> fProcessToBias;
};
#endif
