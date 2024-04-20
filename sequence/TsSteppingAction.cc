#include "TsSteppingAction.hh"

#include "TsParameterManager.hh"
#include "TsSequenceManager.hh"

#include "TsTrackInformation.hh"

#include "G4SteppingManager.hh"
#include "G4Run.hh"
#include "G4Tokenizer.hh"
#include "G4SystemOfUnits.hh"

TsSteppingAction::TsSteppingAction(TsParameterManager* pM, TsSequenceManager* sqM):
fPm(pM), fSqm(sqM), fNumStepsInThisEvent(0), fIsNewTraversedVolume(true), fIsNewInteractionVolume(true), fMostRecentStep(0)
{
	fSqm->RegisterSteppingAction(this);
	fMaxStepNumber = fPm->GetIntegerParameter("Ts/MaxStepNumber");
}


TsSteppingAction::~TsSteppingAction()
{;}


void TsSteppingAction::CacheNeedsSteppingAction() {
	fNeedsSteppingAction = fPm->NeedsSteppingAction();
}

void TsSteppingAction::UserSteppingAction(const G4Step* aStep)
{
	fNumStepsInThisEvent++;
	fMostRecentStep = aStep;

	if (aStep->GetTrack()->GetCurrentStepNumber() > fMaxStepNumber) {
		G4String processName;
		if (aStep->GetTrack()->GetCreatorProcess())
			processName = aStep->GetTrack()->GetCreatorProcess()->GetProcessName();
		else
			processName = "Primary";

		fSqm->NoteKilledTrack(aStep->GetPreStepPoint()->GetKineticEnergy(),
							  aStep->GetTrack()->GetParticleDefinition()->GetParticleName(),
							  processName,
							  aStep->GetTrack()->GetVolume()->GetName());
		aStep->GetTrack()->SetTrackStatus(fStopAndKill);
	}

	if (fNeedsSteppingAction) {
		//G4cout << "Step number: " << aStep->GetTrack()->GetCurrentStepNumber() << ", processName: " << aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName() <<
		//", processType: " << aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessType() << G4endl;

		if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
			fIsNewTraversedVolume = true;
			fIsNewInteractionVolume = true;
		}

		if (fIsNewTraversedVolume &&
			(aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessType() == fTransportation) ) {
			fIsNewTraversedVolume = false;
			TsTrackInformation* trackInformation = (TsTrackInformation*)(aStep->GetTrack()->GetUserInformation());
			if (!trackInformation) {
				trackInformation = new TsTrackInformation();
				aStep->GetTrack()->SetUserInformation(trackInformation);
			}
			trackInformation->AddTraversedVolume(aStep->GetPostStepPoint()->GetTouchable()->GetVolume());
		}

		if ((aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessType() != fGeneral) &&
			(aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessType() != fTransportation)) {
			TsTrackInformation* trackInformation = (TsTrackInformation*)(aStep->GetTrack()->GetUserInformation());
			if (!trackInformation) {
				trackInformation = new TsTrackInformation();
				aStep->GetTrack()->SetUserInformation(trackInformation);
			}

			trackInformation->IncrementInteractionCount();

			if (fIsNewInteractionVolume)
				trackInformation->AddInteractionVolume(aStep->GetPostStepPoint()->GetTouchable()->GetVolume());
		}
	}
}


void TsSteppingAction::ClearStepCount() {
	fNumStepsInThisEvent = 0;
}


G4int TsSteppingAction::GetStepCount() {
	return fNumStepsInThisEvent;
}


const G4Step* TsSteppingAction::GetMostRecentStep() {
	return fMostRecentStep;
}
