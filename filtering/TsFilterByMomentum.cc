#include "TsFilterByMomentum.hh"

#include "G4RunManager.hh"

TsFilterByMomentum::TsFilterByMomentum(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
													 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();
}


TsFilterByMomentum::~TsFilterByMomentum()
{;}


void TsFilterByMomentum::ResolveParameters() {
	fMomentum = fPm->GetDoubleParameter(GetFullParmName(GetName()), "Energy");
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByMomentum::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	G4double momentum = aStep->GetTrack()->GetMomentum().mag();

	switch (fTest) {
		case 1 :
			if (momentum < fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (momentum == fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (momentum > fMomentum) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByMomentum::AcceptTrack(const G4Track* aTrack) const {
	if (fParentFilter && !fParentFilter->AcceptTrack(aTrack)) return false;

	G4double momentum = aTrack->GetMomentum().mag();

	switch (fTest) {
		case 1 :
			if (momentum < fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (momentum == fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (momentum > fMomentum) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}
