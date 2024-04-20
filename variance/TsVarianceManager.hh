#ifndef TsVarianceManager_hh
#define TsVarianceManager_hh

#include <vector>
#include <map>
#include "G4Track.hh"
#include "G4ClassificationOfNewTrack.hh"
#include "globals.hh"

class TsParameterManager;
class TsGeometryManager;
class TsPhysicsManager;
class TsVBiasingProcess;

class TsVarianceManager
{
public:
	TsVarianceManager(TsParameterManager* pM, TsGeometryManager* gM, TsPhysicsManager* phM);
	virtual ~TsVarianceManager();

public:
	void Configure();
	void Initialize();
	void Clear();
	void AddBiasingProcess();
	void UpdateForNewRun(G4bool);
	
	G4bool BiasingProcessExists(G4String type, G4int& index);
	
	TsVBiasingProcess* GetBiasingProcessFromList(G4int index);
	
	G4ClassificationOfNewTrack ApplyKillOtherParticles(const G4Track*);
	inline G4bool UseKillOtherParticles() {return fUseKillOtherParticles;};
	
	G4ClassificationOfNewTrack ApplyDirectionalRussianRoulette(const G4Track*);
	inline G4bool UseDirectionalRussianRoulette() {return fUseDirectionalRussianRoulette;};
	
	G4ClassificationOfNewTrack ApplyRangeRejection(const G4Track*);
	inline G4bool UseRangeRejection() {return fUseRangeRejection;};
	
private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	TsPhysicsManager* fPhm;
	
	std::vector<TsVBiasingProcess*> fBiasingProcesses;
	G4bool fUseKillOtherParticles;
	G4int fIndexKillOtherParticles;
	G4bool fUseDirectionalRussianRoulette;
	G4int fIndexDirectionalRussianRoulette;
	G4bool fUseRangeRejection;
	G4int fIndexRangeRejection;
	
};
#endif
