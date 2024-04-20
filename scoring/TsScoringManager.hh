#ifndef TsScoringManager_hh
#define TsScoringManager_hh

#include "globals.hh"
#include <vector>
#include <map>

#include "TsTopasConfig.hh"

#ifdef TOPAS_MT
#include "G4Cache.hh"
#endif

class TsParameterManager;
//class TsExtensionManager;
class TsMaterialManager;
class TsGeometryManager;
class TsFilterManager;

class TsScoringHub;
class TsVScorer;

class G4MultiFunctionalDetector;

//#include "G4RootAnalysisManager.hh"
//#include "G4XmlAnalysisManager.hh"
//#include "g4root.hh"
//#include "g4xml.hh"

class TsScoringManager
{
public:
	//TsScoringManager(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM, TsFilterManager* fm);
	TsScoringManager(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsFilterManager* fm);
	~TsScoringManager();

	void Initialize();
	TsVScorer* InstantiateScorer(G4String scorerName, G4String quantityName, G4String outFileName, G4bool isSubScorer);

	void SetCurrentScorer(TsVScorer* currentScorer);
	void RegisterScorer(TsVScorer* scorer);
	void InstantiateFilters();
	void NoteAnyUseOfChangeableParameters(const G4String& name);
	void UpdateForSpecificParameterChange(G4String parameter);
	void UpdateForNewRun(G4bool rebuiltSomeComponents);

	G4bool HasUnsatisfiedLimits();

	void UpdateForEndOfRun();
	void RestoreResultsFromFile();
	void Finalize();

	TsVScorer* GetMasterScorerByID(G4int uid);
	std::vector<TsVScorer*> GetMasterScorersByName(G4String scorerName);
	G4bool AddUnitEvenIfItIsOne();
	//G4RootAnalysisManager* GetRootAnalysisManager();
	//G4XmlAnalysisManager* GetXmlAnalysisManager();

	G4MultiFunctionalDetector* GetDetector(G4String componentName, TsVScorer* scorer);

	//TsExtensionManager* GetExtensionManager();
	TsScoringHub* GetScoringHub();

private:
	G4String GetFullParmName(const char* parmName);

	TsParameterManager* fPm;
	//TsExtensionManager* fEm;
	TsMaterialManager* fMm;
	TsGeometryManager* fGm;
	TsFilterManager* fFm;

	G4int fVerbosity;
	G4int fTfVerbosity;
	G4bool fAddUnitEvenIfItIsOne;

	//G4RootAnalysisManager* fRootAnalysisManager;
	//G4XmlAnalysisManager* fXmlAnalysisManager;

	TsScoringHub* fScoringHub;

	G4String fQuantityParmName;

	std::map<G4String,G4MultiFunctionalDetector*>* fDetectors;

#ifdef TOPAS_MT
	G4Cache<TsVScorer*> fCurrentScorer;
	G4Cache<G4String> fCurrentScorerName;
#else
	TsVScorer* fCurrentScorer;
	G4String fCurrentScorerName;
#endif

	G4int fUID;
	std::vector<G4String> fOutFileNames;
	std::vector<TsVScorer*> fMasterScorers;
	std::vector<TsVScorer*> fWorkerScorers;
	std::vector<G4int> fWorkerScorerThreadIDs;
	std::multimap< G4String, std::pair<TsVScorer*,G4String> > fChangeableParameterMap;

public:
	inline G4int GetVerbosity() const { return fVerbosity; }
	inline G4int GetTfVerbosity() const { return fTfVerbosity; }
};

#endif
