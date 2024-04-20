#ifndef TsScoreStepCount_hh
#define TsScoreStepCount_hh

#include "TsVBinnedScorer.hh"

class TsScoreStepCount : public TsVBinnedScorer
{
public:
	TsScoreStepCount(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreStepCount();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
