#include "TsFilterByIncidentParticleType.hh"

#include "G4ParticleTable.hh"
#include "G4UIcommand.hh"
#include "G4Track.hh"

TsFilterByIncidentParticleType::TsFilterByIncidentParticleType(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
							   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert) {
	ResolveParameters();
}


TsFilterByIncidentParticleType::~TsFilterByIncidentParticleType()
{;}


void TsFilterByIncidentParticleType::ResolveParameters() {
	fParticleDefs.clear();
	fIsGenericIon.clear();
	fAtomicNumbers.clear();
	fAtomicMasses.clear();
	fCharges.clear();

	G4String* particleNames = fPm->GetStringVector(GetFullParmName(GetName()));
	G4int length = fPm->GetVectorLength(GetFullParmName(GetName()));

	for (G4int i = 0; i < length; i++) {
		TsParticleDefinition resolvedDef = fPm->GetParticleDefinition(particleNames[i]);

		if (!resolvedDef.particleDefinition && ! resolvedDef.isGenericIon) {
			G4cerr << "Topas is exiting due to a serious error in filter setup." << G4endl;
			G4cerr << GetName() << " = " << particleNames[i] << " refers to an unknown particle type." << G4endl;
			fPm->AbortSession(1);
		}

		fParticleDefs.push_back(resolvedDef.particleDefinition);
		fIsGenericIon.push_back(resolvedDef.isGenericIon);
		fAtomicNumbers.push_back(resolvedDef.ionZ);
		fAtomicMasses.push_back(resolvedDef.ionA);
		fCharges.push_back(resolvedDef.ionCharge);
	}

	TsVFilter::ResolveParameters();
}


G4bool TsFilterByIncidentParticleType::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	return Accept(aStep->GetTrack());
}


G4bool TsFilterByIncidentParticleType::Accept(const G4Track*) const {
	for ( size_t i = 0; i < fParticleDefs.size(); i++) {
		if (fIsGenericIon[i]) {
			if (((fAtomicNumbers[i]==fScorer->GetIncidentParticleDefinition()->GetAtomicNumber()) || (fAtomicNumbers[i] == -1 )) &&
				((fAtomicMasses[i] ==fScorer->GetIncidentParticleDefinition()->GetAtomicMass())   || (fAtomicMasses[i]  == -1 )) &&
				((fCharges[i]      ==fScorer->GetIncidentParticleCharge())                        || (fCharges[i]       == 999))) {
					if (fInvert) return false;
					else return true;
				}
		} else {
			if (fParticleDefs[i]==fScorer->GetIncidentParticleDefinition()) {
				if (fInvert) return false;
				else return true;
			}
		}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByIncidentParticleType::AcceptTrack(const G4Track*) const {
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}
