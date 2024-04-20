#ifndef TsScoreOpticalPhotonCount_hh
#define TsScoreOpticalPhotonCount_hh

#include "TsVNtupleScorer.hh"
#include "G4OpBoundaryProcess.hh"

class TsScoreOpticalPhotonCount : public TsVNtupleScorer
{
public:
	TsScoreOpticalPhotonCount(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
				   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	~TsScoreOpticalPhotonCount();

	virtual G4bool ProcessHits(G4Step*,G4TouchableHistory*);

protected:

	G4float fPosX;
	G4float fPosY;
	G4float fPosZ;
	G4float fWaveLength;
	G4float fTime;
	G4int   fOpticalProcessID;

private:
	G4OpBoundaryProcessStatus fExpectedNextStatus;
	G4int fBounceLimit;
	G4int fCounterBounce;
};
#endif
