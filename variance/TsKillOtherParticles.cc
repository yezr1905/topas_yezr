#include "TsKillOtherParticles.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ClassificationOfNewTrack.hh"

#include "globals.hh"
#include <vector>

TsKillOtherParticles::TsKillOtherParticles(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
	: TsVBiasingProcess(name, pM, gM), fPm(pM), fGm(gM), fName(name),
	  fAvoid(false), fInvertFilter(false), fLengthAvoidComponents(0), fParticleName(nullptr)
{
}

TsKillOtherParticles::~TsKillOtherParticles()
{
}

void TsKillOtherParticles::ResolveParameters() {
	G4int sizeOfParticleName;
			
	if (fPm->ParameterExists(GetFullParmName("OnlyTrackParticlesNamed")) &&
		fPm->ParameterExists(GetFullParmName("OnlyTrackParticlesNotNamed"))) {
		G4cerr << "Topas is exiting due to error in variance reduction setup." << G4endl;
		G4cerr << "Parameter:" << G4endl;
		G4cerr << GetFullParmName("OnlyTrackParticlesNamed") << G4endl;
		G4cerr << "is incompatible with parameter:" << G4endl;
		G4cerr << GetFullParmName("OnlyTrackParticlesNotNamed") << G4endl;
		fPm->AbortSession(1);
	}
	
	fInvertFilter = false;
	if (fPm->ParameterExists(GetFullParmName("OnlyTrackParticlesNamed"))) {
		fParticleName = fPm->GetStringVector(GetFullParmName("OnlyTrackParticlesNamed"));
		sizeOfParticleName = fPm->GetVectorLength(GetFullParmName("OnlyTrackParticlesNamed"));
	} else {
		fParticleName = fPm->GetStringVector(GetFullParmName("OnlyTrackParticlesNotNamed"));
		sizeOfParticleName = fPm->GetVectorLength(GetFullParmName("OnlyTrackParticlesNotNamed"));
		fInvertFilter = true;
	}
	
	fParticleDefs.clear();
	fIsGenericIon.clear();
	fAtomicNumbers.clear();
	fAtomicMasses.clear();
	fCharges.clear();
			
	for ( G4int i = 0; i < sizeOfParticleName; i++ ) {
		TsParticleDefinition resolvedDef = fPm->GetParticleDefinition(fParticleName[i]);
		if (!resolvedDef.particleDefinition) {// } && ! resolvedDef.isGenericIon) {
			G4cerr << "Topas is exiting due to error in variance reduction setup." << G4endl;
			if (!fInvertFilter)
				G4cerr << GetFullParmName("OnlyTrackParticlesNamed") + " has unknown particle name: " << fParticleName[i] << G4endl;
			else
				G4cerr << GetFullParmName("OnlyTrackParticlesNotNamed") + " has unknown particle name: " << fParticleName[i] << G4endl;
			
			fPm->AbortSession(1);
		}
				
		fParticleDefs.push_back(resolvedDef.particleDefinition);
		fIsGenericIon.push_back(resolvedDef.isGenericIon);
		fAtomicNumbers.push_back(resolvedDef.ionZ);
		fAtomicMasses.push_back(resolvedDef.ionA);
		fCharges.push_back(resolvedDef.ionCharge);
	}
	
	fAvoid = false;
	if ( fPm->ParameterExists(GetFullParmName("HaveNoEffectInComponentsNamed"))) {
		fAvoid = true;
		G4String* fAvoidComponentName = fPm->GetStringVector(GetFullParmName("HaveNoEffectInComponentsNamed"));
		fLengthAvoidComponents = fPm->GetVectorLength(GetFullParmName("HaveNoEffectInComponentsNamed"));

		for ( int i = 0; i < fLengthAvoidComponents; i++ )
			fAvoidVolumes.push_back( fGm->GetPhysicalVolume( fAvoidComponentName[i] ) );
	}
	
}


void TsKillOtherParticles::Initialize() {
	Clear();
	ResolveParameters();
}


G4ClassificationOfNewTrack TsKillOtherParticles::Apply(const G4Track* aTrack) {
	if ( fAvoid ) {
		for ( int i = 0; i < fLengthAvoidComponents; i++ )
			if (!AcceptVolume(aTrack->GetVolume()) &&
				!AcceptTrack(aTrack))
				return fKill;
	} else {
		if (!AcceptTrack(aTrack))
			return fKill;
	}
	return fUrgent;
}

		
G4bool TsKillOtherParticles::AcceptTrack(const G4Track* aTrack) {
	G4ParticleDefinition* particleDef = aTrack->GetDefinition();
	G4int charge =  (G4int)(aTrack->GetDynamicParticle()->GetCharge());
		
	for ( size_t i = 0; i < fParticleDefs.size(); i++) {
		if (fIsGenericIon[i]) {
			if (((fAtomicNumbers[i]==particleDef->GetAtomicNumber()) || (fAtomicNumbers[i] == -1 )) &&
				((fAtomicMasses[i] ==particleDef->GetAtomicMass())   || (fAtomicMasses[i]  == -1 )) &&
				((fCharges[i]      ==charge)                         || (fCharges[i]       == 999))) {
				if (fInvertFilter) return false;
				else return true;
			}
		} else {
			if (fParticleDefs[i]==particleDef) {
				if (fInvertFilter) return false;
					else return true;
			}
		}
	}
		
	if (fInvertFilter) return true;
	else return false;
}
		
		
G4bool TsKillOtherParticles::AcceptVolume(G4VPhysicalVolume* pv) {
	for ( size_t i = 0; i < fAvoidVolumes.size(); i++ )
		if ( fAvoidVolumes[i] == pv )
			return true;
	return false;
}

		
void TsKillOtherParticles::Clear() {
	fParticleDefs.clear();
	fIsGenericIon.clear();
	fAtomicNumbers.clear();
	fAtomicMasses.clear();
	fCharges.clear();
	return;
}

