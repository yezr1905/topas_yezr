#ifndef TsScoreProtonLET_Denominator_hh
#define TsScoreProtonLET_Denominator_hh

#include "TsVBinnedScorer.hh"

class G4ParticleDefinition;

class TsScoreProtonLET_Denominator : public TsVBinnedScorer
{
public:
	TsScoreProtonLET_Denominator(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
								 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer=false);
	virtual ~TsScoreProtonLET_Denominator();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);

private:
	G4bool fDoseWeighted;
	G4double fMaxScoredLET;
	G4double fNeglectSecondariesBelowDensity;
	G4double fUseFluenceWeightedBelowDensity;

	G4ParticleDefinition* fProtonDefinition;
	G4ParticleDefinition* fElectronDefinition;
	G4int fStepCount;
};

#endif
