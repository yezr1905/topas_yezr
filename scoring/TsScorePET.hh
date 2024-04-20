#ifndef TsScorePET_hh
#define TsScorePET_hh

#include "TsVBinnedScorer.hh"
#include <vector>

class G4Material;

class TsScorePET : public TsVBinnedScorer
{
public:
	TsScorePET(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
			   G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsScorePET();

	G4bool ProcessHits(G4Step*,G4TouchableHistory*);

private:
	G4String* fPETCrossSectionDataNames;
	G4int fNumberOfCrossSectionData;
	std::vector<G4String> fElementName;
	std::vector<G4double> fAbundanceFraction;
	std::vector<G4double> fGramsPerMole;
	std::vector<G4double> fCrossSectionDataBinSize;
	std::vector<std::vector<G4double> > fCrossSectionData;
	G4bool fForceUseHighestEnergyBin;
};
#endif
