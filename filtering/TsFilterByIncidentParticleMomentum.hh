#ifndef TsFilterByIncidentParticleMomentum_hh
#define TsFilterByIncidentParticleMomentum_hh

#include "TsVFilter.hh"

class TsFilterByIncidentParticleMomentum : public TsVFilter
{
public:
	TsFilterByIncidentParticleMomentum(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
									   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test);

	virtual ~TsFilterByIncidentParticleMomentum();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTest;
	G4double fMomentum;
};
#endif

