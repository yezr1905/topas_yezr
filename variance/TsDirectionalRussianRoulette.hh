#ifndef TsDirectionalRussianRoulette_hh
#define TsDirectionalRussianRoulette_hh

#include "TsVBiasingProcess.hh"

#include "G4VPhysicalVolume.hh"
#include "G4Track.hh"
#include "G4Region.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4ClassificationOfNewTrack.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;
class TsVGeometryComponent;

class TsDirectionalRussianRoulette : public TsVBiasingProcess
{
public:
	TsDirectionalRussianRoulette(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsDirectionalRussianRoulette();
	
	void ResolveParameters();
	void Initialize();
	void Clear();
	void AddBiasingProcess() {return;};

	G4ClassificationOfNewTrack Apply(const G4Track* );
	G4bool AcceptTrackDirection(const G4Track*, G4double, G4double);
	
private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	TsVGeometryComponent* fSourceComp;
	
	G4String fName;
	std::vector<G4Region*> fRegion;
	std::map<G4Region*, std::vector<G4double> > fLimit;
	std::map<G4Region*, std::vector<G4double> > fRadius;
	std::map<G4Region*, std::vector<G4String> > fProcesses;
	G4ThreeVector fAxisVector;
	G4ThreeVector fTransVector;
};
#endif
