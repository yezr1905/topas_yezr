#include "TsStackingAction.hh"

#include "TsGeometryManager.hh"
#include "TsVGeometryComponent.hh"
#include "TsGeneratorManager.hh"
#include "TsVarianceManager.hh"

#include "TsVFilter.hh"

#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4RegionStore.hh"
#include "G4VProcess.hh"
#include "G4StackManager.hh"
//#include "G4DNAChemistryManager.hh"

TsStackingAction::TsStackingAction(TsParameterManager *pm, TsGeometryManager *, TsGeneratorManager *pgM, TsVarianceManager *vM)
	: fPm(pm), fPgm(pgM), fVm(vM),
	  fStage(0), fPrimaryCounter(0), fKillTrack(false),
	  fDBSActive(false), fRangeRejection(false)
{
	fKillTrack = fVm->UseKillOtherParticles();
	fDBSActive = fVm->UseDirectionalRussianRoulette();
	fRangeRejection = fVm->UseRangeRejection();
}


TsStackingAction::~TsStackingAction()
{
}


void TsStackingAction::PrepareNewEvent()
{
	fStage = 0;
	fPrimaryCounter = 0;
}


G4ClassificationOfNewTrack TsStackingAction::ClassifyNewTrack(const G4Track* track)
{
	// At stage=0, which means start of event, kill any tracks that fail the appropriate source filter.
	if (fStage==0) {
		fPrimaryCounter++;
		TsVFilter* filter = fPgm->GetFilter(fPrimaryCounter);

		if (filter==0 || filter->AcceptTrack(track))
			return fWaiting;
		else
			return fKill;
	}

	if ( fKillTrack )
		return fVm->ApplyKillOtherParticles(track);
	
	if ( fRangeRejection )
		return fVm->ApplyRangeRejection(track);

	if ( fDBSActive )
		return fVm->ApplyDirectionalRussianRoulette(track);

	return fUrgent;
}


void TsStackingAction::NewStage()
{
	//if ( fPm->NeedsChemistry() && stackManager->GetNTotalTrack() == 0 )
	//	G4DNAChemistryManager::Instance()->Run();

	fStage++;
}


void TsStackingAction::Quit(G4String name, G4String message) {
	G4cerr << "Topas is exiting due to a serious error in variance reduction setup." << G4endl;
	G4cerr << "Parameter name: " << name << G4endl;
	G4cerr << message << G4endl;
	fPm->AbortSession(1);
}
