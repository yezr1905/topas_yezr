#include "TsInelasticSplitProcess.hh"
#include "TsParameterManager.hh"

#include "G4BiasingProcessInterface.hh"
#include "G4ParticleChangeForLoss.hh"
#include "G4ParticleTable.hh"
#include <vector>

TsInelasticSplitProcess::TsInelasticSplitProcess(TsParameterManager*, G4String name)
	: G4VBiasingOperation(name), fSplittingFactor(1), fUseRussianRoulette(false), fName(name)
{}

TsInelasticSplitProcess::TsInelasticSplitProcess(G4String name)
	: G4VBiasingOperation(name), fSplittingFactor(1), fUseRussianRoulette(false), fName(name)
{}

TsInelasticSplitProcess::~TsInelasticSplitProcess()
{}


G4VParticleChange* TsInelasticSplitProcess::
ApplyFinalStateBiasing(const G4BiasingProcessInterface* callingProcess,
					   const G4Track*                            track,
					   const G4Step*                              step,
					   G4bool&                                         ) {
	G4VParticleChange* processFinalState = callingProcess->GetWrappedProcess()->PostStepDoIt(*track, *step);
	
	if ( fSplittingFactor == 1 )
		return processFinalState;
	
	if ( processFinalState->GetNumberOfSecondaries() == 0 )
		return processFinalState;
	
	G4double secondaryWeight = track->GetWeight()/fSplittingFactor;

	G4ParticleChangeForLoss* actualParticleChange = ( G4ParticleChangeForLoss* ) processFinalState;
	
	fParticleChange.Initialize(*track);
	fParticleChange.ProposeTrackStatus(actualParticleChange->GetTrackStatus());
	fParticleChange.ProposeEnergy(actualParticleChange->GetProposedKineticEnergy());
	fParticleChange.ProposeMomentumDirection(actualParticleChange->GetProposedMomentumDirection());
	
	std::vector<G4Track*> totalSecondaries;
	for ( G4int i = 0; i < fSplittingFactor; i++ ) {
		processFinalState = callingProcess->GetWrappedProcess()->PostStepDoIt(*track, *step);
		for ( G4int j = 0 ; j < processFinalState->GetNumberOfSecondaries() ; j++) {
			if (fUseRussianRoulette) {
				G4bool accept = false;
				for ( size_t t = 0; t < fParticleDefs.size(); t++ ) {
					if ( processFinalState->GetSecondary(j)->GetParticleDefinition() ==
						fParticleDefs[t]) {
						accept = true;
						break;
					}
				}
				
				if ( accept ) {
					G4Track* secTrack = processFinalState->GetSecondary(j);
					secTrack->SetWeight(secondaryWeight);
					totalSecondaries.push_back(secTrack);
				}
				
			} else {
				G4Track* secTrack = processFinalState->GetSecondary(j);
				secTrack->SetWeight(secondaryWeight);
				totalSecondaries.push_back(secTrack);
			}
		}
	}
	
	fParticleChange.SetNumberOfSecondaries( G4int(totalSecondaries.size()) );
	fParticleChange.SetSecondaryWeightByProcess(true);
	
	for ( auto &secTrack : totalSecondaries )
		fParticleChange.AddSecondary(secTrack);
	
	totalSecondaries.clear();
	processFinalState->Clear();
	actualParticleChange->Clear();
	
	return &fParticleChange;
}


void TsInelasticSplitProcess::SetSplittingFactor(G4int splittingFactor) {
	fSplittingFactor = splittingFactor;
}


void TsInelasticSplitProcess::SetRussianRouletteForParticles(std::vector<G4ParticleDefinition*> partDefs ) {
	fParticleDefs = partDefs;
	if ( fParticleDefs.size() > 0 )
		fUseRussianRoulette = true;
}


G4int TsInelasticSplitProcess::GetSplittingFactor() const {
	return fSplittingFactor;
}
