#ifndef TsFilterByInvert_hh
#define TsFilterByInvert_hh

#include "TsVFilter.hh"

class TsFilterByInverse : public TsVFilter
{
public:
	TsFilterByInverse(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
					  TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert);

	virtual ~TsFilterByInverse();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4bool fDoInvert;
};
#endif

