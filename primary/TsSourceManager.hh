#ifndef TsSourceManager_hh
#define TsSourceManager_hh

#include "globals.hh"

#include <map>

class TsParameterManager;
class TsGeometryManager;
//class TsExtensionManager;
class TsSequenceManager;

class TsSource;

class TsSourceManager
{
public:
	TsSourceManager(TsParameterManager* pM, TsGeometryManager* gM);
	~TsSourceManager();

	void Initialize(TsSequenceManager* sqM);
	void SetCurrentSource(TsSource* currentSource);
	void NoteAnyUseOfChangeableParameters(const G4String& name);
	void UpdateForSpecificParameterChange(G4String parameter);
	void UpdateForNewRun(G4bool rebuiltSomeComponents);
	void UpdateForEndOfRun();

	void Finalize();

	TsSource* GetSource(G4String sourceName);

	TsGeometryManager* GetGeometryManager();

	G4bool RandomModeNeedsMoreRuns();

	G4int GetNumberOfHistoriesInRun();

	void AddSourceFromGUI(G4String& sourceName, G4String& componentName, G4String& typeName);

private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	//TsExtensionManager* fEm;
	TsSequenceManager* fSqm;

	G4int fVerbosity;

	TsSource* fCurrentSource;
	std::map<G4String, TsSource*>* fSources;
	std::multimap< G4String, std::pair<TsSource*,G4String> > fChangeableParameterMap;
};

#endif
