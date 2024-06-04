#include "TsFilterByPrimaryKE.hh"

#include "TsTrackInformation.hh"

TsFilterByPrimaryKE::TsFilterByPrimaryKE(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
										 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();

	if (scorer)
		pM->SetNeedsTrackingAction();
}


TsFilterByPrimaryKE::~TsFilterByPrimaryKE()
{;}


void TsFilterByPrimaryKE::ResolveParameters() {
	fKE = fPm->GetDoubleParameter(GetFullParmName(GetName()), "Energy");
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByPrimaryKE::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	TsTrackInformation* parentInformation = (TsTrackInformation*)(aStep->GetTrack()->GetUserInformation());
	G4double primaryKE;

	if (parentInformation && parentInformation->GetParentTrackVertexKineticEnergies().size() > 0)
		primaryKE = parentInformation->GetParentTrackVertexKineticEnergies().back();
	else
		primaryKE = aStep->GetTrack()->GetVertexKineticEnergy();

	switch (fTest) {
		case 1 :
			if (primaryKE < fKE) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (primaryKE == fKE) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (primaryKE > fKE) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByPrimaryKE::AcceptTrack(const G4Track* aTrack) const {
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
