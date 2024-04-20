#ifndef TsScoreFluence_hh
#define TsScoreFluence_hh

#include "TsVBinnedScorer.hh"

class TsScoreFluence : public TsVBinnedScorer
{
public:
	TsScoreFluence(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
				   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreFluence();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif

