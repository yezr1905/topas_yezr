#ifndef TsGeometricalParticleSplit_hh
#define TsGeometricalParticleSplit_hh

#include "G4GeometryCell.hh"
#include "G4VPhysicalVolume.hh"
#include "TsGeometrySampler.hh"

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsGeometricalParticleSplit : public TsVBiasingProcess
{
public:
	TsGeometricalParticleSplit(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsGeometricalParticleSplit();

	void ResolveParameters();
	void SetBiasingProcess(std::vector<TsGeometrySampler*> tgs);
	void Clear();
	void SetGeometry();
	void Initialize();
	void SetGeometricalParticleSplit();
	void AddBiasingProcess();
	
	G4String GetName() {return fName;};
	G4String GetTypeName() {return fType;};
	
	std::vector<TsGeometrySampler*> GetGeometrySampler();
	
private:
	TsGeometryManager*	fGm;
	TsParameterManager* fPm;

	G4String fName;
	G4String* fParticleName;
	G4int fParticleNameLength;
	G4String fType;
	G4String fWorldBiasingName;
	G4String fComponentName;
	G4String* fSubComponentNames;
	G4int fSubCompSize;
	G4int fVerbosity;
	
	std::vector<G4VPhysicalVolume*> fPhysVol;
	std::vector<TsGeometrySampler*> fGeometrySampler;
};
#endif
