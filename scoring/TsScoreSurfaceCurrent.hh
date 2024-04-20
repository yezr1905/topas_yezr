#ifndef TsScoreSurfaceCurrent_hh
#define TsScoreSurfaceCurrent_hh

#include "TsVBinnedScorer.hh"

class TsScoreSurfaceCurrent : public TsVBinnedScorer
{
public:
	TsScoreSurfaceCurrent(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						  G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreSurfaceCurrent();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
};
#endif

