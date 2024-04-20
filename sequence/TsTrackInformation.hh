#ifndef TsTrackInformation_hh
#define TsTrackInformation_hh

#include "G4ParticleDefinition.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserTrackInformation.hh"
#include "G4ThreeVector.hh"
#include "G4Track.hh"
#include "G4PrimaryVertex.hh"

class G4VProcess;

class TsTrackInformation : public G4VUserTrackInformation
{
  public:
	TsTrackInformation();
	~TsTrackInformation();

	void AddParticleDef(G4ParticleDefinition* particleDef);
	void AddParticleCharge(G4int charge);
	void AddOriginVolume(G4VPhysicalVolume* volume);
	void AddTraversedVolume(G4VPhysicalVolume* volume);
	void AddAncestorTraversedVolume(G4VPhysicalVolume* volume);
	void AddInteractionVolume(G4VPhysicalVolume* volume);
	void AddAncestorInteractionVolume(G4VPhysicalVolume* volume);
	void AddCreatorProcess(G4VProcess* process);
	void AddParentTrack(const G4Track* parentTrack);
	void AddParentTrackID(G4int parentTrackID);
	void AddParentTrackVertexPosition(G4ThreeVector parentTrackVertexPosition);
	void AddParentTrackVertexMomentumDirection(G4ThreeVector parentTrackVertexMomentumDirection);
	void AddParentTrackVertexKineticEnergy(G4double parentTrackVertexKineticEnergy);
	void SetSplitTrackID(G4int splitTrackID);
	void IncrementInteractionCount();

	std::vector<G4ParticleDefinition*> GetParticleDefs();
	std::vector<G4int> GetParticleCharges();
	std::vector<G4VPhysicalVolume*> GetOriginVolumes();
	std::vector<G4VPhysicalVolume*> GetTraversedVolumes();
	std::vector<G4VPhysicalVolume*> GetAncestorTraversedVolumes();
	std::vector<G4VPhysicalVolume*> GetInteractionVolumes();
	std::vector<G4VPhysicalVolume*> GetAncestorInteractionVolumes();
	std::vector<G4VProcess*> GetCreatorProcesses();
	std::vector<const G4Track*> GetParentTracks();
	std::vector<G4int> GetParentTrackIDs();
	std::vector<G4ThreeVector> GetParentTrackVertexPositions();
	std::vector<G4ThreeVector> GetParentTrackVertexMomentumDirections();
	std::vector<G4double> GetParentTrackVertexKineticEnergies();
	G4int GetSplitTrackID();
	G4int GetInteractionCount();

  private:
	std::vector<G4ParticleDefinition*> fParticleDefs;
	std::vector<G4int> fParticleCharges;
	std::vector<G4VPhysicalVolume*> fOriginVolumes;
	std::vector<G4VPhysicalVolume*> fTraversedVolumes;
	std::vector<G4VPhysicalVolume*> fAncestorTraversedVolumes;
	std::vector<G4VPhysicalVolume*> fAncestorInteractionVolumes;
	std::vector<G4VPhysicalVolume*> fInteractionVolumes;
	std::vector<G4VProcess*> fCreatorProcesses;
	std::vector<const G4Track*> fParentTracks;
	std::vector<G4int> fParentTrackIDs;
	std::vector<G4ThreeVector> fParentTrackVertexPositions;
	std::vector<G4ThreeVector> fParentTrackVertexMomentumDirections;
	std::vector<G4double> fParentTrackVertexKineticEnergies;
	G4int fSplitTrackID;
	G4int fInteractionCount;
};

#endif
