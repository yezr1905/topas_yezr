#include "TsFilterByInverse.hh"

TsFilterByInverse::TsFilterByInverse(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
									 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
	: TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert),
	  fDoInvert(false)
{
	ResolveParameters();
}

TsFilterByInverse::~TsFilterByInverse()
{;}


void TsFilterByInverse::ResolveParameters() {
	fDoInvert = fPm->GetBooleanParameter(GetFullParmName(GetName()));
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByInverse::Accept(const G4Step* aStep) const {
	if (fDoInvert)
		return !fParentFilter->Accept(aStep);
	else
		return fParentFilter->Accept(aStep);
}


G4bool TsFilterByInverse::AcceptTrack(const G4Track* aTrack) const {
	if (fDoInvert)
		return !fParentFilter->AcceptTrack(aTrack);
	else
		return fParentFilter->AcceptTrack(aTrack);
}
