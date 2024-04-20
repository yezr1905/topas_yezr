#ifndef TsAutomaticImportanceSamplingOperator_hh
#define TsAutomaticImportanceSamplingOperator_hh 1

#include "G4VBiasingOperator.hh"
#include "G4LogicalVolume.hh"

class TsParameterManager;
class G4VBiasingOperation;

class TsAutomaticImportanceSamplingOperator : public G4VBiasingOperator
{
public:
	TsAutomaticImportanceSamplingOperator(TsParameterManager* pM, G4String name);
	virtual ~TsAutomaticImportanceSamplingOperator();
	
	virtual void      StartRun();
	G4bool IsApplicable(G4LogicalVolume*);
	
private:
	virtual G4VBiasingOperation*
	ProposeNonPhysicsBiasingOperation(const G4Track*,
									  const G4BiasingProcessInterface*);
	
	virtual G4VBiasingOperation*
	ProposeOccurenceBiasingOperation (const G4Track*,
									  const G4BiasingProcessInterface*)
	{ return 0; }
	
	virtual G4VBiasingOperation*
	ProposeFinalStateBiasingOperation(const G4Track*,
									  const G4BiasingProcessInterface*)
	{ return 0; }

private:
	TsParameterManager*           fPm;
	G4VBiasingOperation* fImportanceOperation;
	
	G4String* fAcceptedLogicalVolumeNames;
	G4int     fNbOfAcceptedLogicalVolumeNames;
	
	std::map<G4int, G4double> fImportanceValues;
	std::vector<G4int> fDivisionCounts;
};
#endif
