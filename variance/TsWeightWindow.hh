#ifndef TsWeightWindow_hh
#define TsWeightWindow_hh

#include "G4GeometryCell.hh"
#include "G4VPhysicalVolume.hh"
#include "G4GeometrySampler.hh"

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsWeightWindow : public TsVBiasingProcess
{
public:
	TsWeightWindow(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsWeightWindow();

	void ResolveParameters();
	void SetGeometrySampler();
	void Clear();
	void SetGeometry();
	void Initialize();
	void SetWeightWindow();
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
	G4String fBiasingWorld;
	G4String fComponentName;
	G4String* fSubComponentNames;
	G4int fSubCompSize;
	G4bool fIsParallel;
	
	G4bool fGeometryAlreadyBuilt;
	G4bool fClearSampling;
	
	G4int fVerbosity;
};
#endif
