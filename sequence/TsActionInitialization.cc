#include "TsActionInitialization.hh"

#include "TsParameterManager.hh"
//#include "TsExtensionManager.hh"
#include "TsGeometryManager.hh"
#include "TsSourceManager.hh"
#include "TsFilterManager.hh"
//#include "TsChemistryManager.hh"
#include "TsVarianceManager.hh"
#include "TsSequenceManager.hh"

#include "TsGeneratorManager.hh"

#include "TsEventAction.hh"
#include "TsStackingAction.hh"
#include "TsTrackingAction.hh"
#include "TsSteppingAction.hh"

#include "G4RunManager.hh"

#ifdef TOPAS_MT
#include "G4AutoLock.hh"

namespace {
	G4Mutex generatorManagerMutex = G4MUTEX_INITIALIZER;
}
#endif

//TsActionInitialization::TsActionInitialization(TsParameterManager* pM, TsExtensionManager* eM,
//											   TsGeometryManager* gM, TsSourceManager* soM,
//											   TsFilterManager* fM, TsChemistryManager* chM,
//											   TsVarianceManager* vM, TsSequenceManager* sqM) :
//#ifdef TOPAS_MT
//G4VUserActionInitialization(),
//#endif
//fPm(pM), fEm(eM), fGm(gM), fSom(soM), fFm(fM), fChm(chM), fVm(vM), fSqm(sqM)
TsActionInitialization::TsActionInitialization(TsParameterManager* pM,
	TsGeometryManager* gM, TsSourceManager* soM,
	TsFilterManager* fM,
	TsVarianceManager* vM, TsSequenceManager* sqM) :
#ifdef TOPAS_MT
	G4VUserActionInitialization(),
#endif
	fPm(pM), fGm(gM), fSom(soM), fFm(fM), fVm(vM), fSqm(sqM)
{
}


TsActionInitialization::~TsActionInitialization()
{;}


void TsActionInitialization::Build() const
{
#ifdef TOPAS_MT
	G4AutoLock l(&generatorManagerMutex);
#endif

	TsGeneratorManager* pgM = new TsGeneratorManager(fPm, fGm, fSom, fFm, fSqm);

	// enable history counting when executing sequence (needed here for MT mode)
	pgM->SetIsExecutingSequence(fSqm->IsExecutingSequence());

#ifdef TOPAS_MT
	SetUserAction(pgM);
	SetUserAction(new TsEventAction(fPm, fSqm));
	SetUserAction(new TsStackingAction(fPm, fGm, pgM, fVm));
	SetUserAction(new TsTrackingAction(fPm));
	SetUserAction(new TsSteppingAction(fPm, fSqm));
#else
	fSqm->SetUserAction(pgM);
	fSqm->SetUserAction(new TsEventAction(fPm, fEm, fSqm));
	fSqm->SetUserAction(new TsStackingAction(fPm, fGm, pgM, fVm));
	fSqm->SetUserAction(new TsTrackingAction(fPm));
	fSqm->SetUserAction(new TsSteppingAction(fPm, fSqm));
#endif
	
	//fChm->Configure();

	// Tell Geant4 to save random number status so that it is available later to write to phase space or console
	G4RunManager::GetRunManager()->StoreRandomNumberStatusToG4Event(1);
}
