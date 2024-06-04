#ifndef TsFilterByWeight_hh
#define TsFilterByWeight_hh

#include "TsVFilter.hh"

class TsFilterByWeight : public TsVFilter
{
public:
	TsFilterByWeight(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
					 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test);

	virtual ~TsFilterByWeight();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTest;
	G4double fWeight;
};
#endif

