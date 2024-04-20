#include "TsScoreOriginCount.hh"

TsScoreOriginCount::TsScoreOriginCount(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
						  G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
						 : TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("");
}


TsScoreOriginCount::~TsScoreOriginCount() {;}


G4bool TsScoreOriginCount::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}
	
	if (aStep->GetTrack()->GetCurrentStepNumber() == 1) {
		AccumulateHit(aStep, 1.);
		return true;
	}
	return false;	
}
