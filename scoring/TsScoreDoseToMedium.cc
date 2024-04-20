#include "TsScoreDoseToMedium.hh"

TsScoreDoseToMedium::TsScoreDoseToMedium(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
								 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("Gy");
}


TsScoreDoseToMedium::~TsScoreDoseToMedium() {;}


G4bool TsScoreDoseToMedium::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double edep = aStep->GetTotalEnergyDeposit();
	if ( edep > 0. ) {
		G4double density = aStep->GetPreStepPoint()->GetMaterial()->GetDensity();

		ResolveSolid(aStep);

		G4double dose = edep / ( density * GetCubicVolume(aStep));
		dose *= aStep->GetPreStepPoint()->GetWeight();

		AccumulateHit(aStep, dose);

		return true;
	}
	return false;
}
