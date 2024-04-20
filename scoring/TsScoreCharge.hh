#ifndef TsScoreCharge_hh
#define TsScoreCharge_hh

#include "TsVBinnedScorer.hh"

class TsScoreCharge : public TsVBinnedScorer
{
public:
	TsScoreCharge(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreCharge();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
