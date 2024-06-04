#include "TsFilterByTimeOfFlight.hh"

TsFilterByTimeOfFlight::TsFilterByTimeOfFlight(G4String name, TsParameterManager* pM, TsMaterialManager* mM,
													   TsGeometryManager* gM, TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert) {
	ResolveParameters();
}


TsFilterByTimeOfFlight::~TsFilterByTimeOfFlight()
{;}


void TsFilterByTimeOfFlight::ResolveParameters() {
	fTimeOfFlightLimit = fPm->GetDoubleParameter(GetFullParmName(GetName()), "Time");
	G4cout << "fTimeOfFlightLImit: " << fTimeOfFlightLimit / ns << G4endl;
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByTimeOfFlight::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	G4cout << "Time: " << aStep->GetTrack()->GetGlobalTime() / ns << G4endl;
	if (aStep->GetTrack()->GetGlobalTime() > fTimeOfFlightLimit) {
		if (fInvert) return false;
		else return true;
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByTimeOfFlight::AcceptTrack(const G4Track*) const {
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}
