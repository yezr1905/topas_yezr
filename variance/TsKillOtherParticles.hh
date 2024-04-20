#ifndef TsKillOtherParticles_hh
#define TsKillOtherParticles_hh

#include "TsVBiasingProcess.hh"

#include "G4VPhysicalVolume.hh"
#include "G4Track.hh"
#include "G4ClassificationOfNewTrack.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsKillOtherParticles : public TsVBiasingProcess
{
public:
	TsKillOtherParticles(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsKillOtherParticles();
	
	void ResolveParameters();
	void Initialize();
	void Clear();
	void AddBiasingProcess() {return;};

	G4ClassificationOfNewTrack Apply(const G4Track* );
	G4bool AcceptTrack(const G4Track*);
	G4bool AcceptVolume(G4VPhysicalVolume* pv);
	
private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	
	G4String fName;
	G4bool fAvoid;
	G4bool fInvertFilter;
	G4int fLengthAvoidComponents;
	std::vector<G4VPhysicalVolume*> fAvoidVolumes;
	G4String* fParticleName;
	std::vector<G4ParticleDefinition*> fParticleDefs;
	std::vector<G4bool> fIsGenericIon;
	std::vector<G4int> fAtomicNumbers;
	std::vector<G4int> fAtomicMasses;
	std::vector<G4int> fCharges;
};
#endif
