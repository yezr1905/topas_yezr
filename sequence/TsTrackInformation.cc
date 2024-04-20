#include "TsTrackInformation.hh"

#include "G4VProcess.hh"

TsTrackInformation::TsTrackInformation() : fSplitTrackID(0), fInteractionCount(0)
{
}

TsTrackInformation::~TsTrackInformation()
{
}

void TsTrackInformation::AddParticleDef(G4ParticleDefinition* particleDef) {
	//G4cout << "Storing ancestor particle def: " << particleDef->GetParticleName() << G4endl;
	fParticleDefs.push_back(particleDef);
}


void TsTrackInformation::AddParticleCharge(G4int charge) {
	//G4cout << "Storing ancestor particle charge: " << charge << G4endl;
	fParticleCharges.push_back(charge);
}


void TsTrackInformation::AddOriginVolume(G4VPhysicalVolume* volume) {
	//if (volume)
	//	G4cout << "Storing ancestor origin volume: " << volume->GetName() << G4endl;
	fOriginVolumes.push_back(volume);
}


void TsTrackInformation::AddTraversedVolume(G4VPhysicalVolume* volume) {
	//if (volume)
	//	G4cout << "Storing traversed volume: " << volume->GetName() << G4endl;
	fTraversedVolumes.push_back(volume);
}


void TsTrackInformation::AddAncestorTraversedVolume(G4VPhysicalVolume* volume) {
	//if (volume)
	//	G4cout << "Storing ancestor traversed volume: " << volume->GetName() << G4endl;
	fAncestorTraversedVolumes.push_back(volume);
}


void TsTrackInformation::AddInteractionVolume(G4VPhysicalVolume* volume) {
	//if (volume)
	//	G4cout << "Storing interaction volume: " << volume->GetName() << G4endl;
	fInteractionVolumes.push_back(volume);
}


void TsTrackInformation::AddAncestorInteractionVolume(G4VPhysicalVolume* volume) {
	//if (volume)
	//	G4cout << "Storing ancestor interaction volume: " << volume->GetName() << G4endl;
	fAncestorInteractionVolumes.push_back(volume);
}


void TsTrackInformation::AddCreatorProcess(G4VProcess* process) {
	//if (process)
	//	G4cout << "Storing ancestor creator process: " << process->GetProcessName() << G4endl;
	fCreatorProcesses.push_back(process);
}


void TsTrackInformation::AddParentTrack(const G4Track* parentTrack) {
	//G4cout << "Storing ancestor track: " << parentTrack << G4endl;
	fParentTracks.push_back(parentTrack);
}


void TsTrackInformation::AddParentTrackID(G4int parentTrackID) {
	//G4cout << "Storing ancestor track ID: " << parentTrackID << G4endl;
	fParentTrackIDs.push_back(parentTrackID);
}


void TsTrackInformation::AddParentTrackVertexPosition(G4ThreeVector parentTrackVertexPosition) {
	//G4cout << "Storing ancestor track vertex position: " << parentTrackVertexPosition << G4endl;
	fParentTrackVertexPositions.push_back(parentTrackVertexPosition);
}


void TsTrackInformation::AddParentTrackVertexMomentumDirection(G4ThreeVector parentTrackVertexMomentumDirection) {
	//G4cout << "Storing ancestor track vertex momentum direction: " << parentTrackVertexMomentumDirection << G4endl;
	fParentTrackVertexMomentumDirections.push_back(parentTrackVertexMomentumDirection);
}


void TsTrackInformation::AddParentTrackVertexKineticEnergy(G4double parentTrackVertexKineticEnergy) {
	//G4cout << "Storing ancestor track vertex kinetic energy: " << parentTrackVertexKineticEnergy << G4endl;
	fParentTrackVertexKineticEnergies.push_back(parentTrackVertexKineticEnergy);
}


void TsTrackInformation::SetSplitTrackID(G4int splitTrackID) {
	fSplitTrackID = splitTrackID;
}


void TsTrackInformation::IncrementInteractionCount() {
	fInteractionCount++;
}


std::vector<G4ParticleDefinition*> TsTrackInformation::GetParticleDefs() {
	return fParticleDefs;
}


std::vector<G4int> TsTrackInformation::GetParticleCharges() {
	return fParticleCharges;
}


std::vector<G4VPhysicalVolume*> TsTrackInformation::GetOriginVolumes() {
	return fOriginVolumes;
}


std::vector<G4VPhysicalVolume*> TsTrackInformation::GetTraversedVolumes() {
	return fTraversedVolumes;
}


std::vector<G4VPhysicalVolume*> TsTrackInformation::GetAncestorTraversedVolumes() {
	return fAncestorTraversedVolumes;
}


std::vector<G4VPhysicalVolume*> TsTrackInformation::GetInteractionVolumes() {
	return fInteractionVolumes;
}


std::vector<G4VPhysicalVolume*> TsTrackInformation::GetAncestorInteractionVolumes() {
	return fAncestorInteractionVolumes;
}


std::vector<G4VProcess*> TsTrackInformation::GetCreatorProcesses() {
	return fCreatorProcesses;
}


std::vector<const G4Track*> TsTrackInformation::GetParentTracks() {
	return fParentTracks;
}


std::vector<G4int> TsTrackInformation::GetParentTrackIDs() {
	return fParentTrackIDs;
}


std::vector<G4ThreeVector> TsTrackInformation::GetParentTrackVertexPositions() {
	return fParentTrackVertexPositions;
}


std::vector<G4ThreeVector> TsTrackInformation::GetParentTrackVertexMomentumDirections() {
	return fParentTrackVertexMomentumDirections;
}


std::vector<G4double> TsTrackInformation::GetParentTrackVertexKineticEnergies() {
	return fParentTrackVertexKineticEnergies;
}


G4int TsTrackInformation::GetSplitTrackID() {
	return fSplitTrackID;
}


G4int TsTrackInformation::GetInteractionCount() {
	return fInteractionCount;
}
