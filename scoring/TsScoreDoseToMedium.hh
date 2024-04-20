#ifndef TsScoreDoseToMedium_hh
#define TsScoreDoseToMedium_hh

#include "TsVBinnedScorer.hh"

class TsScoreDoseToMedium : public TsVBinnedScorer
{
public:
	TsScoreDoseToMedium(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
					   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreDoseToMedium();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif
