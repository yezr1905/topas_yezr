#ifndef TsSplitProcess_hh
#define TsSplitProcess_hh

#include "G4VProcess.hh"
#include "G4FieldTrack.hh"

class TsParameterManager;
class TsGeometryManager;
class TsVGeometryComponent;
class TsIStore;

class G4TransportationManager;
class G4Navigator;
class G4PathFinder;

class TsSplitProcess : public G4VProcess
{
public :
	TsSplitProcess(TsParameterManager*, TsGeometryManager*, const G4String&, TsIStore*);

	virtual ~TsSplitProcess();

	void ResolveParameters();

	virtual G4double PostStepGetPhysicalInteractionLength(const G4Track&, G4double, G4ForceCondition*);
	virtual G4VParticleChange* PostStepDoIt(const G4Track&, const G4Step&);
	virtual G4double AtRestGetPhysicalInteractionLength(const G4Track&, G4ForceCondition*);
	virtual G4VParticleChange* AtRestDoIt(const G4Track&, const G4Step&);
	virtual G4double AlongStepGetPhysicalInteractionLength(const G4Track&, G4double, G4double, G4double&, G4GPILSelection*);
	virtual G4VParticleChange* AlongStepDoIt(const G4Track&, const G4Step& );
	
	void SetParallelWorld(G4String);
	void SetParallelWorld(G4VPhysicalVolume*);
	void StartTracking(G4Track*);
	void Split(G4ParticleChange* , const G4Track& , G4int, G4int);
	void RussianRoulette(G4ParticleChange*, G4int);

	G4int CalculateNSplit(G4int, G4int);
	G4bool AcceptTrack(const G4Track&, G4double, G4double);
	G4String GetFullParmName(G4String parmName);

private:
	void CopyStep(const G4Step& step);

private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	TsVGeometryComponent* fMotherComponent;
	TsIStore* fAIStore;

	G4ParticleChange* fParticleChange;
	G4Step* fGhostStep;
	G4StepPoint* fGhostPreStepPoint;
	G4StepPoint* fGhostPostStepPoint;
	G4TransportationManager* fTransportationManager;
	G4PathFinder* fPathFinder;
	G4Navigator* fGhostNavigator;
	G4int fNavigatorID;
	G4FieldTrack fFieldTrack;
	G4double fGhostSafety;
	G4bool fOnBoundary;

	G4double fRadius;
	G4double fLimit;
	G4ThreeVector fTransVector;
	G4ThreeVector fAxisVector;
	G4double fKCarTolerance;
	G4int fFactor;
	G4ThreeVector fAxisVector1;
	G4ThreeVector fAxisVector2;
	G4String fName;
	G4bool fOnlySplitParticlesOfUnitaryWeight;
};

#endif
