#include "TsAutomaticImportanceSamplingManager.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericBiasingPhysics.hh"

#include "globals.hh"
#include <vector>

TsAutomaticImportanceSamplingManager::TsAutomaticImportanceSamplingManager(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name)
{
	ResolveParameters();
}


TsAutomaticImportanceSamplingManager::~TsAutomaticImportanceSamplingManager()
{;}


void TsAutomaticImportanceSamplingManager::ResolveParameters() {
    fParticlesToBias = fPm->GetStringVector(GetFullParmName("ParticlesNamed"));
    fNbOfParticles = fPm->GetVectorLength(GetFullParmName("ParticlesNamed"));
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
}


void TsAutomaticImportanceSamplingManager::Initialize() {
	SetGenericBiasing();
}


void TsAutomaticImportanceSamplingManager::SetGenericBiasing() {
	return;
}


G4GenericBiasingPhysics* TsAutomaticImportanceSamplingManager::GetGenericBiasingPhysics() {
	G4GenericBiasingPhysics* biasingPhysics = new G4GenericBiasingPhysics(fName);
	for ( int i = 0; i < fNbOfParticles; i++ )
		biasingPhysics->NonPhysicsBias(fParticlesToBias[i]);
	
    return biasingPhysics;
}


void TsAutomaticImportanceSamplingManager::Clear() {
	return;
}
