#ifndef TsGeneratorPhaseSpace_hh
#define TsGeneratorPhaseSpace_hh

#include "TsVGenerator.hh"

#include <queue>

class TsGeneratorPhaseSpace : public TsVGenerator
{
public:
	TsGeneratorPhaseSpace(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorPhaseSpace();

	void ResolveParameters();

	void UpdateForNewRun(G4bool rebuiltSomeComponents);
	void ClearGenerator();

	void GeneratePrimaries(G4Event* );

private:
	std::queue<TsPrimaryParticle>* fParticleBuffer;
};

#endif
