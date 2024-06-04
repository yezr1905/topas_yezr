#ifndef TsPseudoFilter_hh
#define TsPseudoFilter_hh

#include "TsVFilter.hh"

class TsPseudoFilter : public TsVFilter
{
public:
	TsPseudoFilter(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer);

	virtual ~TsPseudoFilter();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;
};
#endif

