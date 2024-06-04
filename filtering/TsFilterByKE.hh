#ifndef TsFilterByKE_hh
#define TsFilterByKE_hh

#include "TsVFilter.hh"

class TsFilterByKE : public TsVFilter
{
public:
	TsFilterByKE(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
						TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test);

	virtual ~TsFilterByKE();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTest;
	G4double fKE;
};
#endif

