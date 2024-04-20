#ifndef TsScoreEffectiveCharge_hh
#define TsScoreEffectiveCharge_hh

#include "TsVBinnedScorer.hh"

class TsScoreEffectiveCharge : public TsVBinnedScorer
{
public:
	TsScoreEffectiveCharge(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreEffectiveCharge();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
