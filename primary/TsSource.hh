#ifndef TsSource_hh
#define TsSource_hh

#include "globals.hh"

class TsParameterManager;
class TsSourceManager;
class TsVGeometryComponent;

class TsSource
{
public:
	TsSource(TsParameterManager* pM, TsSourceManager* psM, G4String sourceName);
	~TsSource();

	// Handle time-dependent parameter changes
	virtual void UpdateForSpecificParameterChange(G4String parameter);

	// Do any special work needed at end of run
	virtual void UpdateForEndOfRun();

	// Get name of this particle source
	G4String GetName();

protected:
	// Resolve any parameters needed by the concrete source
	virtual void ResolveParameters();

	// Gives full parameter name given just last part
	G4String GetFullParmName(const char* parmName);

	// Pointer to parameter manager
	TsParameterManager* fPm;

	// Pointer to Component
	TsVGeometryComponent* fComponent;

	// User classes should not access any methods or data beyond this point

public:
	virtual void UpdateForNewRun(G4bool rebuiltSomeComponents);

	G4int GetNumberOfHistoriesInRun();
	G4long GetNumberOfHistoriesInRandomJob();
	G4double GetProbabilityOfUsingAGivenRandomTime();
	G4bool RandomModeNeedsMoreRuns();

	void NoteNumberOfHistoriesGenerated(G4int number);
	void NoteNumberOfParticlesGenerated(G4long number);
	void NoteNumberOfParticlesSkipped(G4long number);

	void Finalize();

protected:
	G4String fSourceName;

	G4long fNumberOfHistoriesInRun;

private:
	TsSourceManager* fPsm;

	G4int fVerbosity;

	G4bool fHadParameterChangeSinceLastRun;

	G4double fProbabilityOfUsingAGivenRandomTime;
	G4long fNumberOfHistoriesInRandomJob;
	G4long fTotalHistoriesGenerated;
	G4long fTotalParticlesGenerated;
	G4long fTotalParticlesSkipped;
};

#endif
