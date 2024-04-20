#include "TsScoreFluence.hh"

TsScoreFluence::TsScoreFluence(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
							   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("/mm2");
}


TsScoreFluence::~TsScoreFluence() {;}


G4bool TsScoreFluence::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double quantity = aStep->GetStepLength();

	if ( quantity > 0.) {
		ResolveSolid(aStep);

		quantity /= GetCubicVolume(aStep);
		quantity *= aStep->GetPreStepPoint()->GetWeight();

		AccumulateHit(aStep, quantity);

		return true;
	}
	return false;
}
