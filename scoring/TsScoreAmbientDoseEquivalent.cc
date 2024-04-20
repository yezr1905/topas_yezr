#include "TsScoreAmbientDoseEquivalent.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

TsScoreAmbientDoseEquivalent::TsScoreAmbientDoseEquivalent(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
							   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVBinnedScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
	SetUnit("Sv");

	G4String particleName = fPm->GetStringParameter(GetFullParmName("GetAmbientDoseEquivalentForParticleNamed"));
	fParticleDefinition = G4ParticleTable::GetParticleTable()->FindParticle(particleName);

	fEnergies = fPm->GetDoubleVector(GetFullParmName("FluenceToDoseConversionEnergies"), "Energy");
	fCoefficients = fPm->GetDoubleVector(GetFullParmName("FluenceToDoseConversionValues"), "dose fluence");
	fBins = fPm->GetVectorLength(GetFullParmName("FluenceToDoseConversionEnergies"));
	if ( fBins != fPm->GetVectorLength(GetFullParmName("FluenceToDoseConversionValues"))) {
		G4cout << "TOPAS is exiting due to error in scoring setup." << G4endl;
		G4cout << "Scorer " << GetName() << " has quantity AmbientDoseEquivalent" << G4endl;
		G4cout << "but vector length of the conversion factor and energies mismatch." << G4endl;
		fPm->AbortSession(1);
	}
}


TsScoreAmbientDoseEquivalent::~TsScoreAmbientDoseEquivalent() {;}


G4bool TsScoreAmbientDoseEquivalent::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	if (!fIsActive) {
		fSkippedWhileInactive++;
		return false;
	}

	G4double quantity = aStep->GetStepLength();

	if ( quantity > 0. && aStep->GetTrack()->GetParticleDefinition()==fParticleDefinition) {
		ResolveSolid(aStep);
		G4double ekin = aStep->GetTrack()->GetKineticEnergy();

		quantity /= GetCubicVolume(aStep);
		quantity *= aStep->GetPreStepPoint()->GetWeight();

	   G4double coefficient = 0;
		for ( int i = fBins-1; i >= 0; i-- ) {
			if ( ekin >= fEnergies[i] ) {
				coefficient = fCoefficients[i] + ( fCoefficients[i+1] - fCoefficients[i] ) * ( ekin - fEnergies[i] ) / ( fEnergies[i+1] - fEnergies[i] );
				break;
			}
		}
	   quantity *= coefficient;
		AccumulateHit(aStep, quantity);

		return true;
	}
	return false;
}
