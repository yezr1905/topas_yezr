#include "TsPseudoFilter.hh"

TsPseudoFilter::TsPseudoFilter(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, 0, false)
{;}


TsPseudoFilter::~TsPseudoFilter()
{;}


G4bool TsPseudoFilter::Accept(const G4Step* aStep) const {
	if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary)
	    fScorer->NoteIncidentParticleInfo(aStep);

	return true;
}


G4bool TsPseudoFilter::AcceptTrack(const G4Track*) const
{
	return true;
}
