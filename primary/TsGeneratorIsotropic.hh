#ifndef TsGeneratorIsotropic_hh
#define TsGeneratorIsotropic_hh

#include "TsVGenerator.hh"

class TsGeneratorIsotropic : public TsVGenerator
{
public:
	TsGeneratorIsotropic(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorIsotropic();

	void ResolveParameters();

	void GeneratePrimaries(G4Event* );
};

#endif
