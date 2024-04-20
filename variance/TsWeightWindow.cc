#include "TsWeightWindow.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"
#include "TsVGeometryComponent.hh"

#include "G4WeightWindowStore.hh"
#include "G4WeightWindowAlgorithm.hh"
#include "G4PlaceOfAction.hh"
#include "G4ProcessPlacer.hh"
#include "G4GeometrySampler.hh"
#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"

#include "globals.hh"
#include <vector>

TsWeightWindow::TsWeightWindow(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fGm(gM), fPm(pM), fName(name), fIsParallel(false),
fGeometryAlreadyBuilt(false), fClearSampling(false), fVerbosity(0)
{
	ResolveParameters();
	SetGeometrySampler();
}


TsWeightWindow::~TsWeightWindow()
{;}


void TsWeightWindow::ResolveParameters() {
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
	fType.toLower();
	
	fParticleName = fPm->GetStringVector(GetFullParmName("ParticleName"));
	fParticleNameLength = fPm->GetVectorLength(GetFullParmName("ParticleName"));
	
	fComponentName = fPm->GetStringParameter(GetFullParmName("Component"));
	fSubComponentNames = fPm->GetStringVector(GetFullParmName("SubComponents"));
	fSubCompSize = fPm->GetVectorLength(GetFullParmName("SubComponents"));
	
	G4int weSize = fPm->GetVectorLength(GetFullParmName("WeightMap"));
	G4int emSize = fPm->GetVectorLength(GetFullParmName("EnergyMap"));
	
	if ( fSubCompSize != emSize )
		Quit(GetFullParmName("EnergyMap"), "The number of elements must matches with " +
			 GetFullParmName("SubComponents"));
	
	if ( fSubCompSize != weSize )
		Quit(GetFullParmName("WeightMap"), "The number of elements must matches with " +
			 GetFullParmName("SubComponents"));
	
	fVerbosity = fPm->GetIntegerParameter("Ts/SequenceVerbosity");
}


void TsWeightWindow::Initialize() {
	if ( !fGeometryAlreadyBuilt )
		SetGeometry();
	
	SetWeightWindow();
}


void TsWeightWindow::SetGeometry() {
	G4VPhysicalVolume* physWorld = fGm->GetComponent(fComponentName)->GetParentVolume();
	G4VPhysicalVolume* physComponent = fGm->GetPhysicalVolume(fComponentName);
	
	fPhysVol.push_back(physWorld);
	fPhysVol.push_back(physComponent);
	
	for ( int i = 0; i < fSubCompSize; i++ )
		fPhysVol.push_back(fGm->GetPhysicalVolume(fSubComponentNames[i]));
}


void TsWeightWindow::SetWeightWindow() {
	G4double* upperEnergyBounds = fPm->GetDoubleVector(GetFullParmName("EnergyMap"), "Energy");
	G4double* lowerWeights = fPm->GetUnitlessVector(GetFullParmName("WeightMap"));
	std::map<G4double, G4double, std::less<G4double> > upperEnergyLowerWeight;
	upperEnergyLowerWeight.insert(std::pair<G4double, G4double>(upperEnergyBounds[0], lowerWeights[0]));
	
	if (fClearSampling)
		G4WeightWindowStore::GetInstance()->Clear();
	
	//G4WeightWindowStore* wwstore = G4WeightWindowStore::GetInstance(*fPhysVol[0]->GetName());
	G4WeightWindowStore* wwstore = G4WeightWindowStore::GetInstance(fPhysVol[0]->GetName());
	
	G4GeometryCell world(*(fPhysVol[0]), 0);
	G4GeometryCell component(*(fPhysVol[1]), 0);
	
	if (fClearSampling && fVerbosity > 1) {
		G4cout << "Going to reassing lower weight: " << lowerWeights[0]
		<< ",\t With energy bound: " << upperEnergyBounds[0]
		<< ",\t to component: " << world.GetPhysicalVolume().GetName() << G4endl;
	} else {
		G4cout << "Going to assing lower weight: " << lowerWeights[0]
		<< ",\t With energy bound: " << upperEnergyBounds[0]
		<< ",\t to component: " << world.GetPhysicalVolume().GetName() << G4endl;
	}
	
	wwstore->AddUpperEboundLowerWeightPairs(world, upperEnergyLowerWeight);
	wwstore->AddUpperEboundLowerWeightPairs(component, upperEnergyLowerWeight);
	
	for ( int i = 0; i < fSubCompSize; i++ ) {
		G4GeometryCell aSubComponent( *fPhysVol[i+2], 0);
		upperEnergyLowerWeight.clear();
		upperEnergyLowerWeight.insert( std::pair<G4double, G4double>(upperEnergyBounds[i], lowerWeights[i]) );
		if (fClearSampling && fVerbosity > 1) {
			G4cout << "Going to reassing lower weight: " << lowerWeights[i]
			<< ",\t With energy bound: " << upperEnergyBounds[i]
			<< ",\t to component: " << aSubComponent.GetPhysicalVolume().GetName() << G4endl;
		} else {
			G4cout << "Going to assing lower weight: " << lowerWeights[i]
			<< ",\t With energy bound: " << upperEnergyBounds[i]
			<< ",\t to component: " << aSubComponent.GetPhysicalVolume().GetName() << G4endl;
		}
		wwstore->AddUpperEboundLowerWeightPairs(aSubComponent, upperEnergyLowerWeight);
	}
}


void TsWeightWindow::SetGeometrySampler() {
	G4String compName;
	if (fGm->GetComponent(fComponentName)->IsParallel()) {
		fIsParallel = true;
		compName = fComponentName;
		fBiasingWorld = fComponentName;
	} else {
		compName = "World";
		fBiasingWorld = "World";
	}
	
	G4WeightWindowStore* iwwStore = G4WeightWindowStore::GetInstance(compName);
	
	for ( int i = 0; i < fParticleNameLength; i++ ) {
		G4GeometrySampler* pgs = new G4GeometrySampler(compName, fParticleName[i]);
		if (fIsParallel) {
			pgs->SetParallel(true);
			pgs->SetWorld(iwwStore->GetParallelWorldVolumePointer());
		}
		fGeometrySampler.push_back(pgs);
	}
}


void TsWeightWindow::AddBiasingProcess() {
	G4double upperLimitFactor = fPm->GetUnitlessParameter(GetFullParmName("UpperLimitFactor"));
	G4double survivalFactor = fPm->GetUnitlessParameter(GetFullParmName("SurvivalFactor"));
	G4int maximumSplitNumber = fPm->GetIntegerParameter(GetFullParmName("MaximumSplitNumber"));
	G4String placeOfAction = fPm->GetStringParameter(GetFullParmName("PlaceOfAction"));
	placeOfAction.toLower();
	G4PlaceOfAction thePlaceOfAction = onBoundary;
	if ( placeOfAction == "oncollision")
		thePlaceOfAction = onCollision;
	else if ( placeOfAction == "onboundaryandcollision" )
		thePlaceOfAction = onBoundaryAndCollision;
	else if ( placeOfAction != "onboundary" ){
		Quit(placeOfAction, "Refers to an unknown place of action for weight window technique");
	}
	
	G4WeightWindowAlgorithm* wwAlg = new G4WeightWindowAlgorithm( upperLimitFactor, survivalFactor, maximumSplitNumber);
	for ( int i = 0; i < int(fGeometrySampler.size()); i++) {
		if ( !G4Threading::IsWorkerThread() ) {
			fGeometrySampler[i]->PrepareWeightWindow(G4WeightWindowStore::GetInstance(fBiasingWorld), wwAlg, thePlaceOfAction);
			fGeometrySampler[i]->Configure();
		}
		fGeometrySampler[i]->AddProcess();
	}
}


void TsWeightWindow::Clear() {
	fClearSampling = true;
}
