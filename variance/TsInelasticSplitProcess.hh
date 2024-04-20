#ifndef TsInelasticSplitProcess_hh
#define TsInelasticSplitProcess_hh 1

#include "G4VBiasingOperation.hh"
#include "G4ParticleChange.hh"
#include "G4ParticleDefinition.hh"
#include <vector>

class TsParameterManager;

class TsInelasticSplitProcess : public G4VBiasingOperation
{	
public:
	TsInelasticSplitProcess(TsParameterManager* pM, G4String name);
	TsInelasticSplitProcess(G4String name);
	virtual ~TsInelasticSplitProcess();
	
public:
	virtual const G4VBiasingInteractionLaw* ProvideOccurenceBiasingInteractionLaw(const G4BiasingProcessInterface*,
																				  G4ForceCondition& ) { return 0; };
	
	
	virtual G4VParticleChange*   ApplyFinalStateBiasing( const G4BiasingProcessInterface*,
														const G4Track*,
														const G4Step*,
														G4bool& );
	
	virtual G4double           DistanceToApplyOperation( const G4Track*,
														G4double,
														G4ForceCondition*) {return DBL_MAX;};
	
	
	virtual G4VParticleChange* GenerateBiasingFinalState( const G4Track*,
														 const G4Step*   ) {return 0;};
	
	void  SetSplittingFactor(G4int splittingFactor);
	
	void  SetRussianRouletteForParticles(std::vector<G4ParticleDefinition*> partDefs);
	
	G4int GetSplittingFactor() const;
	
private:
	G4int            fSplittingFactor;
	G4ParticleChange fParticleChange;
	std::vector<G4ParticleDefinition*> fParticleDefs;
	G4bool fUseRussianRoulette;
	G4String fName;
};
#endif
