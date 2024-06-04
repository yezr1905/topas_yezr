#include "TsFilterByInitialMomentum.hh"

#include "TsTrackingAction.hh"

#include "G4RunManager.hh"

TsFilterByInitialMomentum::TsFilterByInitialMomentum(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
													 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();

	if (scorer)
		pM->SetNeedsTrackingAction();
}


TsFilterByInitialMomentum::~TsFilterByInitialMomentum()
{;}


void TsFilterByInitialMomentum::ResolveParameters() {
	fMomentum = fPm->GetDoubleParameter(GetFullParmName(GetName()), "Energy");
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByInitialMomentum::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	G4double initialMomentum = ((TsTrackingAction*)(G4RunManager::GetRunManager()->GetUserTrackingAction()))->GetInitialMomentum();

	switch (fTest) {
		case 1 :
			if (initialMomentum < fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (initialMomentum == fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (initialMomentum > fMomentum) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByInitialMomentum::AcceptTrack(const G4Track* aTrack) const {
	if (fParentFilter && !fParentFilter->AcceptTrack(aTrack)) return false;

	switch (fTest) {
		case 1 :
			if (aTrack->GetMomentum().mag() < fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (aTrack->GetMomentum().mag() == fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (aTrack->GetMomentum().mag() > fMomentum) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}
