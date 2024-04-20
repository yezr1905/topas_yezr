#ifndef TsGeneratorEnvironment_hh
#define TsGeneratorEnvironment_hh

#include "TsVGenerator.hh"

#include "G4VPhysicalVolume.hh"
#include "G4Point3D.hh"

class G4Navigator;
class G4Material;

class TsGeneratorEnvironment : public TsVGenerator
{
public:
	TsGeneratorEnvironment(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorEnvironment();

	void ResolveParameters();
	void UpdateForNewRun(G4bool rebuiltSomeComponents);

	void GeneratePrimaries(G4Event* );
	
private:
	void CalculateExtent();
	
	G4bool fRecursivelyIncludeChildren;
	G4Navigator* fNavigator;
	G4int fMaxNumberOfPointsToSample;
	
	std::vector<G4VPhysicalVolume*> fVolumes;

	G4bool fNeedToCalculateExtent;

	G4double  fRadius;
	G4Point3D fCentre;
};

#endif
