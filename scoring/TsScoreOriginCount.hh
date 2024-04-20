#ifndef TsScoreOriginCount_hh
#define TsScoreOriginCount_hh

#include "TsVBinnedScorer.hh"

class TsScoreOriginCount : public TsVBinnedScorer
{
public:
	TsScoreOriginCount(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
				G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreOriginCount();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
