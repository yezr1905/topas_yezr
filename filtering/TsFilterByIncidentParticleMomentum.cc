#include "TsFilterByIncidentParticleMomentum.hh"

TsFilterByIncidentParticleMomentum::TsFilterByIncidentParticleMomentum(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
																	   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();
}


TsFilterByIncidentParticleMomentum::~TsFilterByIncidentParticleMomentum()
{;}


void TsFilterByIncidentParticleMomentum::ResolveParameters() {
	fMomentum = fPm->GetDoubleParameter(GetFullParmName(GetName()), "Energy");
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByIncidentParticleMomentum::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	// No matter what the condition, only score if have an incident track
	if (!fScorer->HaveIncidentParticle()) {
		fScorer->NoteHitHadNoIncidentParticle();
		return false;
	}

	switch (fTest) {
		case 1 :
			if (fScorer->GetIncidentParticleMomentum() < fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (fScorer->GetIncidentParticleMomentum() == fMomentum) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (fScorer->GetIncidentParticleMomentum() > fMomentum) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByIncidentParticleMomentum::AcceptTrack(const G4Track*) const {
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}
