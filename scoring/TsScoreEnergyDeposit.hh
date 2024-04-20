#ifndef TsScoreEnergyDeposit_hh
#define TsScoreEnergyDeposit_hh

#include "TsVBinnedScorer.hh"

class TsScoreEnergyDeposit : public TsVBinnedScorer
{
public:
	TsScoreEnergyDeposit(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreEnergyDeposit();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
