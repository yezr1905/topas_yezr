#include "TsFilterByInitialKE.hh"

TsFilterByInitialKE::TsFilterByInitialKE(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
										 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();
}


TsFilterByInitialKE::~TsFilterByInitialKE()
{;}


void TsFilterByInitialKE::ResolveParameters() {
	fKE = fPm->GetDoubleParameter(GetFullParmName(GetName()), "Energy");
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByInitialKE::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	switch (fTest) {
		case 1 :
			if (aStep->GetTrack()->GetVertexKineticEnergy() < fKE) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (aStep->GetTrack()->GetVertexKineticEnergy() == fKE) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (aStep->GetTrack()->GetVertexKineticEnergy() > fKE) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByInitialKE::AcceptTrack(const G4Track* aTrack) const {
	if (fParentFilter && !fParentFilter->AcceptTrack(aTrack)) return false;

	switch (fTest) {
		case 1 :
			if (aTrack->GetKineticEnergy() < fKE) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (aTrack->GetKineticEnergy() == fKE) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (aTrack->GetKineticEnergy() > fKE) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}
