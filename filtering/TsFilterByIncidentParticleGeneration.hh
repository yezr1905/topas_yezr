#ifndef TsFilterByIncidentParticleGeneration_hh
#define TsFilterByIncidentParticleGeneration_hh

#include "TsVFilter.hh"

class TsFilterByIncidentParticleGeneration : public TsVFilter
{
public:
	TsFilterByIncidentParticleGeneration(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
						 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert);
	virtual ~TsFilterByIncidentParticleGeneration();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4bool fAcceptPrimary;
	G4bool fAcceptSecondary;
};
#endif

