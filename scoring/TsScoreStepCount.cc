#include "TsScoreStepCount.hh"

TsScoreStepCount::TsScoreStepCount(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
								   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("");
}


TsScoreStepCount::~TsScoreStepCount() {;}


G4bool TsScoreStepCount::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double weight = aStep->GetPreStepPoint()->GetWeight();
	if ( weight > 0. ) {
		AccumulateHit(aStep, weight);

		return true;
	}
	return false;
}
