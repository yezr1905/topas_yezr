#ifndef TsSourceDistributed_hh
#define TsSourceDistributed_hh

#include "TsSource.hh"

#include "G4Point3D.hh"
#include <vector>

class TsSourceDistributed : public TsSource
{
public:
	TsSourceDistributed(TsParameterManager* pM, TsSourceManager* psM, G4String sourceName);
	~TsSourceDistributed();

	void UpdateForNewRun(G4bool rebuiltSomeComponents);

	void ResolveParameters();

	void PrepareSampledPoints();
	
	std::vector<G4Point3D*> fSampledPoints;

private:
	G4int fNumberOfSourcePoints;
	G4int fPreviousNumberOfSourcePoints;
	G4bool fRedistributePointsOnNewRun;
	
	enum DistributionType { FLAT, GAUSSIAN };
	DistributionType fPointDistribution;

	G4double fPointDistributionSigma;
};

#endif
