#ifndef TsAutomaticImportanceSamplingParallelManager_hh
#define TsAutomaticImportanceSamplingParallelManager_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;
class G4GenericBiasingPhysics;

class TsAutomaticImportanceSamplingParallelManager : public TsVBiasingProcess
{
public:
	TsAutomaticImportanceSamplingParallelManager(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsAutomaticImportanceSamplingParallelManager();

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
	G4String* fParticlesToBias;
	G4String fParallelWorldName;
};
#endif
