#ifndef TsScoreKineticEnergyAtSurface_hh
#define TsScoreKineticEnergyAtSurface_hh

#include "TsVBinnedScorer.hh"

class TsScoreKineticEnergyAtSurface : public TsVBinnedScorer
{
public:
	TsScoreKineticEnergyAtSurface(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreKineticEnergyAtSurface();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif


