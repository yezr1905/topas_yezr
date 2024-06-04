#ifndef TsFilterManager_hh
#define TsFilterManager_hh

#include "globals.hh"

#include <map>
#include <vector>

#include "TsTopasConfig.hh"

#ifdef TOPAS_MT
#include "G4Cache.hh"
#endif

class TsParameterManager;
//class TsExtensionManager;
class TsMaterialManager;
class TsGeometryManager;
class TsFilterManager;

class TsVFilter;
class TsVGenerator;
class TsVScorer;
class TsFilterHub;

class G4Material;

class TsFilterManager
{
public:
	//TsFilterManager(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM);
	TsFilterManager(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM);
	~TsFilterManager();

	void SetCurrentFilter(TsVFilter* currentFilter);
	void NoteAnyUseOfChangeableParameters(const G4String& name);
	void UpdateForSpecificParameterChange(G4String parameter);
	void UpdateForNewRun(G4bool rebuiltSomeComponents);

	TsVFilter* InstantiateFilter(TsVGenerator* generator);
	TsVFilter* InstantiateFilter(TsVScorer* scorer);
	TsVFilter* InstantiateFilter(TsVGenerator* generator, TsVScorer* scorer);

private:
	TsParameterManager* fPm;
	//TsExtensionManager* fEm;
	TsMaterialManager* fMm;
	TsGeometryManager* fGm;

	G4int fTfVerbosity;

	TsFilterHub* fFilterHub;

#ifdef TOPAS_MT
	G4Cache<TsVFilter*> fCurrentFilter;
#else
	TsVFilter* fCurrentFilter;
#endif

	std::vector<TsVFilter*> fFilters;
	std::multimap< G4String, std::pair<TsVFilter*,G4String> > fChangeableParameterMap;
};

#endif
