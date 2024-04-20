#ifndef TsGeneratorPhaseSpaceOld_hh
#define TsGeneratorPhaseSpaceOld_hh

#include "TsVGenerator.hh"

#include <queue>

class TsGeneratorPhaseSpaceOld : public TsVGenerator
{
public:
	TsGeneratorPhaseSpaceOld(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorPhaseSpaceOld();

	void ResolveParameters();

	void UpdateForNewRun(G4bool rebuiltSomeComponents);
	void ClearGenerator();

	void GeneratePrimaries(G4Event* );

private:
	G4long fNumberOfHistoriesToReadFromFile;
	std::queue<TsPrimaryParticle>* fParticleBuffer;
};

#endif
