#ifndef TsInelasticSplitOperator_hh
#define TsInelasticSplitOperator_hh 1

#include "G4VBiasingOperator.hh"

class TsParameterManager;
class TsInelasticSplitProcess;
class G4ParticleDefinition;

class TsInelasticSplitOperator : public G4VBiasingOperator
{
public:
	TsInelasticSplitOperator(TsParameterManager* pM, G4String name);
	virtual ~TsInelasticSplitOperator();
	
	virtual void      StartRun();
	
	virtual void StartTracking( const G4Track* track );
	
	G4bool IsApplicable(G4LogicalVolume*);
	
private:
	virtual G4VBiasingOperation*
	ProposeNonPhysicsBiasingOperation(const G4Track*,
									  const G4BiasingProcessInterface*)
	{ return 0; }
	virtual G4VBiasingOperation*
	ProposeOccurenceBiasingOperation (const G4Track*,
									  const G4BiasingProcessInterface*)
	{ return 0; }
	
	virtual G4VBiasingOperation*
	ProposeFinalStateBiasingOperation(const G4Track* track,
									  const G4BiasingProcessInterface*);
	
	using G4VBiasingOperator::OperationApplied;
	
private:
	TsParameterManager*           fPm;
	TsInelasticSplitProcess* fSplittingOperation;
	
	G4int     fSplittingFactor;
	G4bool    fBiasPrimaryOnly;
	G4bool    fBiasOnlyOnce;
	G4int     fNInteractions;
	G4String* fAcceptedLogicalVolumeNames;
	G4int     fNbOfAcceptedLogicalVolumeNames;
	std::vector<G4ParticleDefinition*> fParticleDefs;
};
#endif
