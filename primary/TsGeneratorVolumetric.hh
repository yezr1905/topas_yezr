#ifndef TsGeneratorVolumetric_hh
#define TsGeneratorVolumetric_hh

#include "TsVGenerator.hh"

#include "G4VPhysicalVolume.hh"

class G4Navigator;
class G4Material;

class TsGeneratorVolumetric : public TsVGenerator
{
public:
	TsGeneratorVolumetric(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorVolumetric();

	void ResolveParameters();
	void UpdateForNewRun(G4bool rebuiltSomeComponents);

	void GeneratePrimaries(G4Event* );
	
private:
	void CalculateExtent();
	
	G4bool fRecursivelyIncludeChildren;
	G4Navigator* fNavigator;
	G4Material* fActiveMaterial;
	G4int fMaxNumberOfPointsToSample;
	
	std::vector<G4VPhysicalVolume*> fVolumes;

	G4bool fNeedToCalculateExtent;

	G4double fXMin;
	G4double fXMax;
	G4double fYMin;
	G4double fYMax;
	G4double fZMin;
	G4double fZMax;
};

#endif
