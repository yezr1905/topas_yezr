#ifndef TsAutomaticImportanceSamplingParallelOperator_hh
#define TsAutomaticImportanceSamplingParallelOperator_hh 1

#include "G4VBiasingOperator.hh"
#include "G4LogicalVolume.hh"

class TsParameterManager;
class G4VBiasingOperation;
class G4BiasingProcessSharedData;
class G4BiasingProcessSharedData;
class G4ParallelGeometriesLimiterProcess;

class TsAutomaticImportanceSamplingParallelOperator : public G4VBiasingOperator
{
public:
	TsAutomaticImportanceSamplingParallelOperator(TsParameterManager* pM, G4String name);
	virtual ~TsAutomaticImportanceSamplingParallelOperator();
	
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

public:
	void SetParallelWorld(G4VPhysicalVolume*);
	G4String GetParallelWorldName();
	
private:
	TsParameterManager*           fPm;
	G4VBiasingOperation* fImportanceOperation;
	
	const G4ParticleDefinition*  fParticleToBias;
	G4VPhysicalVolume* fParallelWorld;
	G4int fParallelWorldIndex;
	G4String fParallelWorldName;
	const G4BiasingProcessSharedData* fBiasingSharedData;
	const G4ParallelGeometriesLimiterProcess* fBiasingLimiterProcess;
	
	G4String* fAcceptedLogicalVolumeNames;
	G4int     fNbOfAcceptedLogicalVolumeNames;
	
	std::map<G4int, G4double> fImportanceValues;
	std::vector<G4int> fDivisionCounts;
};
#endif
