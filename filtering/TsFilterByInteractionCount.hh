#ifndef TsFilterByInteractionCount_hh
#define TsFilterByInteractionCount_hh

#include "TsVFilter.hh"

class TsFilterByInteractionCount : public TsVFilter
{
public:
	TsFilterByInteractionCount(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
									TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test);
	virtual ~TsFilterByInteractionCount();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTest;
	G4int fInteractionCountLimit;
};
#endif

