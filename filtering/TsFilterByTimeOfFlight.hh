#ifndef TsFilterByTimeOfFlight_hh
#define TsFilterByTimeOfFlight_hh

#include "TsVFilter.hh"

class TsFilterByTimeOfFlight : public TsVFilter
{
public:
	TsFilterByTimeOfFlight(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
									TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert);
	virtual ~TsFilterByTimeOfFlight();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4int fTimeOfFlightLimit;
};
#endif

