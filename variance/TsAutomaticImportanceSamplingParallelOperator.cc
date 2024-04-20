#include "TsParameterManager.hh"

#include "TsAutomaticImportanceSamplingParallelOperator.hh"
#include "TsAutomaticImportanceSamplingParallelProcess.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4VProcess.hh"

#include "G4BiasingProcessInterface.hh"
#include "G4ParallelGeometriesLimiterProcess.hh"
#include "G4BiasingProcessSharedData.hh"
#include "G4TransportationManager.hh"
#include "G4TouchableHistoryHandle.hh"

TsAutomaticImportanceSamplingParallelOperator::TsAutomaticImportanceSamplingParallelOperator(TsParameterManager* pM, G4String name)
	: G4VBiasingOperator(name), fPm(pM), fParallelWorld(nullptr),
	  fParallelWorldIndex(-1), fBiasingSharedData(nullptr), fBiasingLimiterProcess(nullptr)
{
	fImportanceOperation = new TsAutomaticImportanceSamplingParallelProcess(fPm, name);
	fAcceptedLogicalVolumeNames = fPm->GetStringVector("Vr/" + name + "/ApplyBiasingInVolumesNamed");
	fNbOfAcceptedLogicalVolumeNames = fPm->GetVectorLength("Vr/" + name + "/ApplyBiasingInVolumesNamed");
	if ( fNbOfAcceptedLogicalVolumeNames > 1 ) {
		G4cerr << "TOPAS is exiting due to a serius problem in variance reduction setup" << G4endl;
		G4cerr << "For automatic importance sampling, only one volume (binned) is allowed" << G4endl;
		fPm->AbortSession(1);
	}
	
	fParallelWorldName = fPm->GetStringParameter("Vr/" + name + "/Component");
	
	fParticleToBias = G4ParticleTable::GetParticleTable()->FindParticle("e-");
	
	G4String inputFile = fPm->GetStringParameter("Vr/" + name + "/InputFile" );
	std::ifstream in(inputFile);
	if (!in.good() ) {
		G4cerr << "TOPAS is exiting due to a serius problem in variance reduction setup" << G4endl;
		G4cerr << "For automatic importance sampling parameter:" << G4endl;
		G4cerr << "Vr/" + name + "/InputFile. Input file not found" << G4endl;
		fPm->AbortSession(1);
	}
					
	G4int xbins = fPm->GetIntegerParameter("Ge/" + fAcceptedLogicalVolumeNames[0] + "/XBins");
	G4int ybins = fPm->GetIntegerParameter("Ge/" + fAcceptedLogicalVolumeNames[0] + "/YBins");
	G4int zbins = fPm->GetIntegerParameter("Ge/" + fAcceptedLogicalVolumeNames[0] + "/ZBins");
	G4double importance;
	G4cout << "[VRT] Assigning importance values " << G4endl;
	for ( int ii = 0; ii < xbins; ii++ ) {
		for ( int jj = 0; jj < ybins; jj++ ) {
			for ( int kk = 0; kk < zbins; kk++ ) {
				G4int idx = ii*ybins*zbins + jj*zbins + kk;
				in.read(reinterpret_cast<char*>(&importance), sizeof(importance));
				fImportanceValues[idx] = importance;
			}
		}
	}
	G4cout << "[VRT] Assigned importance values " << G4endl;
	fDivisionCounts.clear();
	fDivisionCounts.push_back(xbins);
	fDivisionCounts.push_back(ybins);
	fDivisionCounts.push_back(zbins);
	in.close();
}


TsAutomaticImportanceSamplingParallelOperator::~TsAutomaticImportanceSamplingParallelOperator()
{}


void TsAutomaticImportanceSamplingParallelOperator::StartRun() {
	G4cout << GetName() << " : starting run " << G4endl;
	const G4ProcessManager* processManager = fParticleToBias->GetProcessManager();
	fBiasingSharedData = G4BiasingProcessInterface::GetSharedData( processManager );
	fBiasingLimiterProcess = fBiasingSharedData->GetParallelGeometriesLimiterProcess();
	fParallelWorldIndex    = fBiasingLimiterProcess->GetParallelWorldIndex(fParallelWorld);
	
	((TsAutomaticImportanceSamplingParallelProcess*)fImportanceOperation)->SetBiasingSharedData( fBiasingSharedData  );
	((TsAutomaticImportanceSamplingParallelProcess*)fImportanceOperation)->SetParallelWorldIndex( fParallelWorldIndex );
	
	((TsAutomaticImportanceSamplingParallelProcess*)fImportanceOperation)->SetImportanceValues(fImportanceValues);
	((TsAutomaticImportanceSamplingParallelProcess*)fImportanceOperation)->SetDivisionCounts(fDivisionCounts);
}


G4VBiasingOperation*
TsAutomaticImportanceSamplingParallelOperator::
ProposeNonPhysicsBiasingOperation(const G4Track* track,
								  const G4BiasingProcessInterface*) {
	if (track->GetDefinition() != fParticleToBias) return 0;
	
	return fImportanceOperation;
}


G4bool TsAutomaticImportanceSamplingParallelOperator::IsApplicable(G4LogicalVolume* logicalVolume) {
	G4bool applicable = false;
	for ( int i = 0; i < fNbOfAcceptedLogicalVolumeNames; i++ )
		if ( logicalVolume->GetName() == fAcceptedLogicalVolumeNames[i] )
			applicable = true;
	
	return applicable;
}


void TsAutomaticImportanceSamplingParallelOperator::SetParallelWorld( G4VPhysicalVolume* parallelWorld ) {
	fParallelWorld = parallelWorld;
}


G4String TsAutomaticImportanceSamplingParallelOperator::GetParallelWorldName() {
	return fParallelWorldName;
}
