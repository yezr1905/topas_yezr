#ifndef TsTrackingAction_hh
#define TsTrackingAction_hh

#include "G4UserTrackingAction.hh"

#include "globals.hh"
#include <vector>

class TsParameterManager;
class TsVScorer;

class TsTrackingAction : public G4UserTrackingAction
{
public:
	TsTrackingAction(TsParameterManager* pM);
	~TsTrackingAction();

	void PreUserTrackingAction(const G4Track*);
	void PostUserTrackingAction(const G4Track*);

	void RegisterScorer(TsVScorer* scorer);

	G4double GetInitialMomentum();

private:
	TsParameterManager* fPm;

	G4double fInitialMomentum;

	std::vector<TsVScorer*> fScorers;
    
    G4bool fRequireSplitTrackID;
};

#endif
