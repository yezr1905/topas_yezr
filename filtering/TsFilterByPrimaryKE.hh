#ifndef TsFilterByPrimaryKE_hh
#define TsFilterByPrimaryKE_hh

#include "TsVFilter.hh"

class TsFilterByPrimaryKE : public TsVFilter
{
public:
	TsFilterByPrimaryKE(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
						TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test);

	virtual ~TsFilterByPrimaryKE();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTest;
	G4double fKE;
};
#endif

