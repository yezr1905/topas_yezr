#include "TsScoreEnergyFluence.hh"

TsScoreEnergyFluence::TsScoreEnergyFluence(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
										   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("MeV/mm2");
}


TsScoreEnergyFluence::~TsScoreEnergyFluence() {;}


G4bool TsScoreEnergyFluence::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double quantity = aStep->GetStepLength();

	if ( quantity > 0.) {
		G4double energy = aStep->GetTrack()->GetKineticEnergy();

		if ( energy > 0. ) {
			ResolveSolid(aStep);

			quantity /= GetCubicVolume(aStep);
			quantity *= aStep->GetPreStepPoint()->GetWeight();
			quantity *= energy;

			AccumulateHit(aStep, quantity);

			return true;
		}
	}
	return false;
}
