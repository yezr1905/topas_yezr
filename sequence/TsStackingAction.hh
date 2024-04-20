#ifndef TsStackingAction_hh
#define TsStackingAction_hh

#include "globals.hh"
#include "G4UserStackingAction.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4ParticleDefinition.hh"
#include <vector>
#include <map>

class TsParameterManager;
class TsGeometryManager;
class TsGeneratorManager;
class TsVarianceManager;
class TsVGeometryComponent;
class G4Region;
class G4VPhysicalVolume;

class TsStackingAction : public G4UserStackingAction
{
  public:
	TsStackingAction(TsParameterManager*, TsGeometryManager*, TsGeneratorManager*, TsVarianceManager*);
	~TsStackingAction();

	void PrepareNewEvent();

	G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track*);

	void NewStage();
	
	void Quit(G4String, G4String);

private:
	TsParameterManager *fPm;
	TsGeneratorManager* fPgm;
	TsVarianceManager *fVm;

	G4int fStage;
	G4int fPrimaryCounter;
	
	G4bool fKillTrack;
	G4bool fDBSActive;
	G4bool fRangeRejection;
};

#endif
