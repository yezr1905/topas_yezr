#ifndef TsScoreEnergyFluence_hh
#define TsScoreEnergyFluence_hh

#include "TsVBinnedScorer.hh"

class TsScoreEnergyFluence : public TsVBinnedScorer
{
public:
	TsScoreEnergyFluence(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreEnergyFluence();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif

