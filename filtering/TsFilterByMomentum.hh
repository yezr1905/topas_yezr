#ifndef TsFilterByMomentum_hh
#define TsFilterByMomentum_hh

#include "TsVFilter.hh"

class TsFilterByMomentum : public TsVFilter
{
public:
	TsFilterByMomentum(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							  TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test);

	virtual ~TsFilterByMomentum();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTest;
	G4double fMomentum;
};
#endif

