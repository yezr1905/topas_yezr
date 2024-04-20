#ifndef TsScoreDoseToMaterial_hh
#define TsScoreDoseToMaterial_hh

#include "TsVBinnedScorer.hh"

#include "G4EmCalculator.hh"

class G4Material;

class TsScoreDoseToMaterial : public TsVBinnedScorer
{
public:
	TsScoreDoseToMaterial(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
					   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScoreDoseToMaterial();

	void UpdateForSpecificParameterChange(G4String parameter);

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);

private:
	G4EmCalculator fEmCalculator;
	G4Material* fReferenceMaterial;

	G4ParticleDefinition* fProtonSubstituteForNeutrals;
	G4double fSubstituteForNeutralsEnergy;

	G4bool fPreCalculateStoppingPowerRatios;
	G4double fProtonEnergyBinSize;
	G4int fProtonEnergyNBins;
	G4double fElectronEnergyBinSize;
	G4int fElectronEnergyNBins;
	std::vector<std::vector<G4double> > fProtonStoppingPowerRatio;
	std::vector<std::vector<G4double> > fElectronStoppingPowerRatio;
	std::vector<G4double> fOtherStoppingPowerRatio;
	G4double fMinProtonEnergyForRatio;
	G4double fMaxProtonEnergyForRatio;
	G4double fMinElectronEnergyForRatio;
	G4double fMaxElectronEnergyForRatio;
};
#endif
