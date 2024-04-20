#ifndef TsScoreSurfaceTrackCount_hh
#define TsScoreSurfaceTrackCount_hh

#include "TsVBinnedScorer.hh"

class TsScoreSurfaceTrackCount : public TsVBinnedScorer
{
public:
	TsScoreSurfaceTrackCount(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
							 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreSurfaceTrackCount();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif

