#ifndef TsImportanceSampling_hh
#define TsImportanceSampling_hh

#include "G4GeometryCell.hh"
#include "G4VPhysicalVolume.hh"
#include "G4GeometrySampler.hh"

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsImportanceSampling : public TsVBiasingProcess
{
public:
	TsImportanceSampling(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsImportanceSampling();

	void ResolveParameters();
	void SetGeometrySampler();
	void Clear();
	void SetGeometry();
	void Initialize();
	void SetImportanceSampling();
	void AddBiasingProcess();
	
	G4String GetTypeName() {return fType;};
	G4String GetName() {return fName;};
	
private:
	TsGeometryManager*	fGm;
	TsParameterManager* fPm;

	G4String fName;
	
	std::vector<G4GeometrySampler*> fGeometrySampler;
	
	G4String* fParticleName;
	G4int fParticleNameLength;
	std::vector<G4VPhysicalVolume*> fPhysVol;
	G4String fType;
	G4String fWorldBiasingName;
	G4String fComponentName;
	G4String* fSubComponentNames;
	G4int fSubCompSize;
	G4bool fIsParallel;
	G4bool fGeometryAlreadyBuilt;
	G4bool fCellAlreadyBuilt;
	G4int fVerbosity;
};
#endif
