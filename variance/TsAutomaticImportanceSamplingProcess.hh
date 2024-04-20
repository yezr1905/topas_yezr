#ifndef TsAutomaticImportanceSamplingProcess_hh
#define TsAutomaticImportanceSamplingProcess_hh 1

#include "G4VBiasingOperation.hh"
#include "G4ParticleChange.hh"
#include "G4ParticleChangeForNothing.hh"

#include <vector>

class TsParameterManager;
class G4Region;

class TsAutomaticImportanceSamplingProcess : public G4VBiasingOperation
{	
public:
	TsAutomaticImportanceSamplingProcess(TsParameterManager* pM, G4String name);
	TsAutomaticImportanceSamplingProcess(G4String name);
	virtual ~TsAutomaticImportanceSamplingProcess();
	
public:
	virtual const G4VBiasingInteractionLaw* ProvideOccurenceBiasingInteractionLaw(const G4BiasingProcessInterface*,
																				  G4ForceCondition& ) { return 0; };
	
	
	virtual G4VParticleChange*   ApplyFinalStateBiasing( const G4BiasingProcessInterface*,
														const G4Track*,
														const G4Step*,
														G4bool& ) {return 0;};
	
	virtual G4double           DistanceToApplyOperation( const G4Track*,
														G4double,
														G4ForceCondition*);
	
	
	virtual G4VParticleChange* GenerateBiasingFinalState( const G4Track*,
														 const G4Step*   );
	
	void SetImportanceValues(std::map<G4int, G4double> );
	void SetDivisionCounts(std::vector<G4int> );
	
private:
	G4ParticleChange fParticleChange;
	G4ParticleChangeForNothing fParticleChangeForNothing;
	G4String fName;
	std::map<G4int, G4double> fImportanceValues;
	std::vector<G4int> fDivisionCounts;
};
#endif
