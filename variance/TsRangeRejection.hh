#ifndef TsRangeRejection_hh
#define TsRangeRejection_hh

#include "TsVBiasingProcess.hh"

#include "G4VPhysicalVolume.hh"
#include "G4Track.hh"
#include "G4ClassificationOfNewTrack.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsRangeRejection : public TsVBiasingProcess
{
public:
	TsRangeRejection(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsRangeRejection();
	
	void ResolveParameters();
	void Initialize();
	void Clear();
	void AddBiasingProcess() {return;};

	G4ClassificationOfNewTrack Apply(const G4Track* );
	G4bool ApplyToThisTrack(const G4Track*);
	G4bool ApplyToThisRegion(G4Region*);
	
private:
	TsParameterManager* fPm;
	
	G4String fName;
	G4bool fInvertFilter;
	G4int fNumberOfRegions;
	std::vector<G4Region*> fRegions;
	G4String* fParticleName;
	std::vector<G4ParticleDefinition*> fParticleDefs;
	std::vector<G4bool> fIsGenericIon;
	std::vector<G4int> fAtomicNumbers;
	std::vector<G4int> fAtomicMasses;
	std::vector<G4int> fCharges;
};
#endif
