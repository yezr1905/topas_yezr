#ifndef TsScoreProtonLET_hh
#define TsScoreProtonLET_hh

#include "TsVBinnedScorer.hh"

class G4ParticleDefinition;

class TsScoreProtonLET : public TsVBinnedScorer
{
public:
	TsScoreProtonLET(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
				G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer=false);

	virtual ~TsScoreProtonLET();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);
	G4int CombineSubScorers();

private:
	G4bool fDoseWeighted;
	G4bool fPreStepLookup;
	G4double fMaxScoredLET;
	G4double fNeglectSecondariesBelowDensity;
	G4double fUseFluenceWeightedBelowDensity;

	G4ParticleDefinition* fProtonDefinition;
	G4ParticleDefinition* fElectronDefinition;
	G4int fStepCount;
};
#endif
