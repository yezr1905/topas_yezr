#include "TsFilterByInteractionCount.hh"

#include "TsTrackInformation.hh"

TsFilterByInteractionCount::TsFilterByInteractionCount(G4String name, TsParameterManager* pM, TsMaterialManager* mM,
													   TsGeometryManager* gM, TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();

	pM->SetNeedsSteppingAction();
}


TsFilterByInteractionCount::~TsFilterByInteractionCount()
{;}


void TsFilterByInteractionCount::ResolveParameters() {
	fInteractionCountLimit = fPm->GetIntegerParameter(GetFullParmName(GetName()));
}


G4bool TsFilterByInteractionCount::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	G4int interactionCount = 0;
	TsTrackInformation* parentInformation = (TsTrackInformation*)(aStep->GetTrack()->GetUserInformation());
	if (parentInformation)
		interactionCount = parentInformation->GetInteractionCount();

	switch (fTest) {
		case 1 :
			if (interactionCount < fInteractionCountLimit) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (interactionCount == fInteractionCountLimit) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (interactionCount > fInteractionCountLimit) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByInteractionCount::AcceptTrack(const G4Track*) const {
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}
