#include "TsAutomaticImportanceSamplingParallelManager.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericBiasingPhysics.hh"

#include "globals.hh"
#include <vector>

TsAutomaticImportanceSamplingParallelManager::TsAutomaticImportanceSamplingParallelManager(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name)
{
	ResolveParameters();
}


TsAutomaticImportanceSamplingParallelManager::~TsAutomaticImportanceSamplingParallelManager()
{;}


void TsAutomaticImportanceSamplingParallelManager::ResolveParameters() {
    fParticlesToBias = fPm->GetStringVector(GetFullParmName("ParticlesNamed"));
    fNbOfParticles = fPm->GetVectorLength(GetFullParmName("ParticlesNamed"));
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
	fParallelWorldName = fPm->GetStringParameter(GetFullParmName("Component"));
}


void TsAutomaticImportanceSamplingParallelManager::Initialize() {
	SetGenericBiasing();
}


void TsAutomaticImportanceSamplingParallelManager::SetGenericBiasing() {
	return;
}


G4GenericBiasingPhysics* TsAutomaticImportanceSamplingParallelManager::GetGenericBiasingPhysics() {
	G4GenericBiasingPhysics* biasingPhysics = new G4GenericBiasingPhysics(fName);
	for ( int i = 0; i < fNbOfParticles; i++ ) {
		biasingPhysics->NonPhysicsBias(fParticlesToBias[i]);
		biasingPhysics->AddParallelGeometry(fParticlesToBias[i], fParallelWorldName);
	}
	
    return biasingPhysics;
}


void TsAutomaticImportanceSamplingParallelManager::Clear() {
	return;
}

