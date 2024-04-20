#include "TsScoreSurfaceCurrent.hh"

#include "G4PSDirectionFlag.hh"

TsScoreSurfaceCurrent::TsScoreSurfaceCurrent(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
											 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetSurfaceScorer();
	SetNeedsSurfaceAreaCalculation();
	SetUnit("/mm2");
}


TsScoreSurfaceCurrent::~TsScoreSurfaceCurrent() {;}


G4bool TsScoreSurfaceCurrent::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	ResolveSolid(aStep);

	if (IsSelectedSurface(aStep)) {
		G4double weight = aStep->GetPreStepPoint()->GetWeight();

		if ( weight != 0. ) {
			weight /= GetAreaOfSelectedSurface(aStep);

			AccumulateHit(aStep, weight);

			return true;
		}
	}
	return false;
}
