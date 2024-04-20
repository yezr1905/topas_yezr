#include "TsScoreEnergyDeposit.hh"

TsScoreEnergyDeposit::TsScoreEnergyDeposit(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
										   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("MeV");
}


TsScoreEnergyDeposit::~TsScoreEnergyDeposit() {;}


G4bool TsScoreEnergyDeposit::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double edep = aStep->GetTotalEnergyDeposit();
	if ( edep > 0. ) {
		edep *= aStep->GetPreStepPoint()->GetWeight();

		AccumulateHit(aStep, edep);

		return true;
	}
	return false;
}
