#include "TsScoreEffectiveCharge.hh"

#include "TsVGeometryComponent.hh"

TsScoreEffectiveCharge::TsScoreEffectiveCharge(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
										   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("e+");
}


TsScoreEffectiveCharge::~TsScoreEffectiveCharge() {;}


G4bool TsScoreEffectiveCharge::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4bool status = false;

	// Add charge when particle stops
	if (aStep->GetPostStepPoint()->GetKineticEnergy() == 0) {
		   G4double CellCharge = aStep->GetPreStepPoint()->GetCharge();
		   CellCharge *= aStep->GetPreStepPoint()->GetWeight();
		   AccumulateHit(aStep, CellCharge);
		   status = true;
	   }

	// Subtract charge when particle is generated, except for primaries
	if (aStep->GetTrack()->GetCurrentStepNumber() == 1 && aStep->GetTrack()->GetParentID() != 0) {
		G4double CellCharge = aStep->GetPreStepPoint()->GetCharge();
		CellCharge *= aStep->GetPreStepPoint()->GetWeight();
		CellCharge *= -1.0;
		AccumulateHit(aStep, CellCharge);
		status = true;
	}

	return status;
}
