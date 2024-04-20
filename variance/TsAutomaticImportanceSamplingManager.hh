#ifndef TsAutomaticImportanceSamplingManager_hh
#define TsAutomaticImportanceSamplingManager_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;
class G4GenericBiasingPhysics;

class TsAutomaticImportanceSamplingManager : public TsVBiasingProcess
{
public:
	TsAutomaticImportanceSamplingManager(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsAutomaticImportanceSamplingManager();

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
};
#endif
