#include "TsScoreKineticEnergyAtSurface.hh"

TsScoreKineticEnergyAtSurface::TsScoreKineticEnergyAtSurface(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
															 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("MeV");
}


TsScoreKineticEnergyAtSurface::~TsScoreKineticEnergyAtSurface() {;}


G4bool TsScoreKineticEnergyAtSurface::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double weight = 0.;
	G4TouchableHandle theTouchable = aStep->GetPreStepPoint()->GetTouchableHandle();
	if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
		weight = 1.;
		weight *= aStep->GetPreStepPoint()->GetWeight();

		if ( weight > 0. ) {
			ResolveSolid(aStep);

			AccumulateHit(aStep, weight);

			return true;
		}
	}
	return false;
}
