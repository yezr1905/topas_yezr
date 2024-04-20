#ifndef TsEventAction_hh
#define TsEventAction_hh

#include "G4UserEventAction.hh"

#include "globals.hh"

#include <vector>

class TsParameterManager;
//class TsExtensionManager;
class TsSequenceManager;
class TsVScorer;

class TsEventAction : public G4UserEventAction
{
  public:
	TsEventAction(TsParameterManager* pM, TsSequenceManager* sqM);
	~TsEventAction();

	void BeginOfEventAction(const G4Event*);
	void EndOfEventAction(const G4Event*);

	void RegisterScorer(TsVScorer* scorer);

private:
	TsParameterManager* fPm;
	//TsExtensionManager* fEm;
	TsSequenceManager* fSqm;

	std::vector<TsVScorer*> fScorers;

	G4bool fIsFirstEventInThisThread;
	
	G4int fInterval;
	G4int fNumberOfAnomalousHistoriesInARow;
};

#endif
