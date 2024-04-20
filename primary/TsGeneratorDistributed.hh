#ifndef TsGeneratorDistributed_hh
#define TsGeneratorDistributed_hh

#include "TsVGenerator.hh"

class TsGeneratorDistributed : public TsVGenerator
{
public:
	TsGeneratorDistributed(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorDistributed();

	void GeneratePrimaries(G4Event* );
};

#endif
