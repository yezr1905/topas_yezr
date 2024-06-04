#ifndef TsFilterHub_hh
#define TsFilterHub_hh

#include "G4String.hh"
#include "G4Types.hh"

class TsParameterManager;
//class TsExtensionManager;
class TsMaterialManager;
class TsGeometryManager;
class TsFilterManager;

class TsVFilter;
class TsVGenerator;
class TsVScorer;

class TsFilterHub
{
public:
	TsFilterHub();
	~TsFilterHub();

	//TsVFilter* InstantiateFilter(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM,
	//							 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer);
	TsVFilter* InstantiateFilter(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer);

private:
	G4bool HaveFilterNamed(TsParameterManager* pM, TsVGenerator* generator, TsVScorer* scorer, G4String filterName);
};
#endif
