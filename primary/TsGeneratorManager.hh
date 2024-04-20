#ifndef TsGeneratorManager_hh
#define TsGeneratorManager_hh

#include "G4VUserPrimaryGeneratorAction.hh"

#include "globals.hh"

#include <vector>
#include <map>

class TsParameterManager;
//class TsExtensionManager;
class TsGeometryManager;
class TsSourceManager;
class TsFilterManager;
class TsSequenceManager;

class TsVGenerator;
class TsSource;
class TsVFilter;

class TsGeneratorManager : public G4VUserPrimaryGeneratorAction
{
public:
	TsGeneratorManager(TsParameterManager* pM, TsGeometryManager* gM, TsSourceManager* prM, TsFilterManager* fM,  TsSequenceManager* sqM);
	~TsGeneratorManager();

	TsSource* GetSource(G4String sourceName);
	TsVFilter* GetFilter(G4int primaryCounter);

	void SetIsExecutingSequence(G4bool isExecutingSequence);

	void GeneratePrimaries(G4Event* anEvent);

	void RegisterPrimary(TsVGenerator* generator);

	void SetCurrentGenerator(TsVGenerator* generator);
	void NoteAnyUseOfChangeableParameters(const G4String& name);
	void UpdateForSpecificParameterChange(G4String parameter);
	void UpdateForNewRun(G4bool rebuiltSomeComponents);
	void ClearGenerators();

	void Finalize();

private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	TsSourceManager* fPrm;
	TsFilterManager* fFm;

	G4int fVerbosity;

	G4bool fIsExecutingSequence;

	G4int fPrimaryCounter;

	std::map<G4int,TsVGenerator*>* fGeneratorPerPrimary;

	TsVGenerator* fCurrentGenerator;
	std::vector<TsVGenerator*> fGenerators;
	std::multimap< G4String, std::pair<TsVGenerator*,G4String> > fChangeableParameterMap;
};

#endif
