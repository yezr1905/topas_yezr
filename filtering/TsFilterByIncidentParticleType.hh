#ifndef TsFilterByIncidentParticleType_hh
#define TsFilterByIncidentParticleType_hh

#include "TsVFilter.hh"

#include "G4ParticleDefinition.hh"

class TsFilterByIncidentParticleType : public TsVFilter
{
public:
	TsFilterByIncidentParticleType(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert);
	virtual ~TsFilterByIncidentParticleType();

	void ResolveParameters();

	G4bool Accept(const G4Step*) const;
	G4bool AcceptTrack(const G4Track*) const;

private:
	G4bool Accept(const G4Track* aTrack) const;

	std::vector<G4ParticleDefinition*> fParticleDefs;
	std::vector<G4bool> fIsGenericIon;
	std::vector<G4int> fAtomicNumbers;
	std::vector<G4int> fAtomicMasses;
	std::vector<G4int> fCharges;
};
#endif
