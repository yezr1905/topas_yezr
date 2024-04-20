#ifndef TsSteppingAction_hh
#define TsSteppingAction_hh

#include "G4UserSteppingAction.hh"

#include "globals.hh"

class TsParameterManager;
class TsSequenceManager;

class TsSteppingAction : public G4UserSteppingAction
{
  public:
	TsSteppingAction(TsParameterManager* pM, TsSequenceManager* sqM);
	~TsSteppingAction();

	void CacheNeedsSteppingAction();
	void UserSteppingAction(const G4Step*);
	
	void ClearStepCount();
	G4int GetStepCount();
	const G4Step* GetMostRecentStep();

private:
	TsParameterManager* fPm;
	TsSequenceManager* fSqm;

	G4int fMaxStepNumber;
	G4int fNumStepsInThisEvent;
	G4bool fNeedsSteppingAction;
	G4bool fIsNewTraversedVolume;
	G4bool fIsNewInteractionVolume;
	const G4Step* fMostRecentStep;
};

#endif
