#ifndef TsAutomaticImportanceSamplingParallelProcess_hh
#define TsAutomaticImportanceSamplingParallelProcess_hh 1

#include "G4VBiasingOperation.hh"
#include "G4ParticleChange.hh"
#include "G4ParticleChangeForNothing.hh"
#include "G4TouchableHistoryHandle.hh"

#include <vector>

class TsParameterManager;
class G4BiasingProcessSharedData;

class TsAutomaticImportanceSamplingParallelProcess : public G4VBiasingOperation
{	
public:
	TsAutomaticImportanceSamplingParallelProcess(TsParameterManager* pM, G4String name);
	TsAutomaticImportanceSamplingParallelProcess(G4String name);
	virtual ~TsAutomaticImportanceSamplingParallelProcess();
	
public:
	virtual const G4VBiasingInteractionLaw* ProvideOccurenceBiasingInteractionLaw(const G4BiasingProcessInterface*,
																				  G4ForceCondition& ) final { return 0; };
	
	
	virtual G4VParticleChange*   ApplyFinalStateBiasing( const G4BiasingProcessInterface*,
														const G4Track*,
														const G4Step*,
														G4bool& ) final {return 0;};
	
	virtual G4double           DistanceToApplyOperation( const G4Track*,
														G4double,
														G4ForceCondition*) final;
	
	
	virtual G4VParticleChange* GenerateBiasingFinalState( const G4Track*,
														 const G4Step*   ) final;
	
	void  SetParallelWorldIndex( G4int parallelWorldIndex );
	G4int GetParallelWorldIndex() const;
	void SetBiasingSharedData( const G4BiasingProcessSharedData* sharedData );
	
	void SetImportanceValues(std::map<G4int, G4double> );
	void SetDivisionCounts(std::vector<G4int> );
	
private:
	G4ParticleChange fParticleChange;
	G4ParticleChangeForNothing fParticleChangeForNothing;
	G4String fName;
	G4int                                   fParallelWorldIndex;
	const G4BiasingProcessSharedData*        fBiasingSharedData;
	G4TouchableHistoryHandle           fPreStepTouchableHistory;
	G4TouchableHistoryHandle          fPostStepTouchableHistory;
	std::map<G4int, G4double> fImportanceValues;
	std::vector<G4int> fDivisionCounts;
};
#endif
