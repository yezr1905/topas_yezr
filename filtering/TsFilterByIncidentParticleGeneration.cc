#include "TsFilterByIncidentParticleGeneration.hh"

TsFilterByIncidentParticleGeneration::TsFilterByIncidentParticleGeneration(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
										   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert) {
	ResolveParameters();
}


TsFilterByIncidentParticleGeneration::~TsFilterByIncidentParticleGeneration()
{;}


void TsFilterByIncidentParticleGeneration::ResolveParameters() {
	fAcceptPrimary = false;
	fAcceptSecondary = false;

	G4String acceptGeneration = fPm->GetStringParameter(GetFullParmName(GetName()));
#if GEANT4_VERSION_MAJOR >= 11
	G4StrUtil::to_lower(acceptGeneration);
#else
	acceptGeneration.toLower();
#endif
	if (acceptGeneration=="primary") fAcceptPrimary = true;
	if (acceptGeneration=="secondary") fAcceptSecondary = true;

	TsVFilter::ResolveParameters();
}


G4bool TsFilterByIncidentParticleGeneration::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	if (fAcceptPrimary   && fScorer->GetIncidentParticleParentID() == 0 ) {
		if (fInvert) return false;
		else return true;
	}

	if (fAcceptSecondary && fScorer->GetIncidentParticleParentID() != 0 ) {
		if (fInvert) return false;
		else return true;
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByIncidentParticleGeneration::AcceptTrack(const G4Track*) const {
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}
