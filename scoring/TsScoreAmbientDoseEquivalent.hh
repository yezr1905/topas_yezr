#ifndef TsScoreAmbientDoseEquivalent_hh
#define TsScoreAmbientDoseEquivalent_hh

#include "TsVBinnedScorer.hh"

class G4ParticleDefinition;

class TsScoreAmbientDoseEquivalent : public TsVBinnedScorer
{
public:
	TsScoreAmbientDoseEquivalent(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
				   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreAmbientDoseEquivalent();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);

private:
	G4ParticleDefinition* fParticleDefinition;
	G4double* fEnergies;
	G4double* fCoefficients;
	G4int fBins;

};
#endif

