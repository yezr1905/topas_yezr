#include "TsInelasticSplitManager.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericBiasingPhysics.hh"

#include "globals.hh"
#include <vector>

TsInelasticSplitManager::TsInelasticSplitManager(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name)
{
	ResolveParameters();
}


TsInelasticSplitManager::~TsInelasticSplitManager()
{;}


void TsInelasticSplitManager::ResolveParameters() {
    fProcessesToBias = fPm->GetStringVector(GetFullParmName("ProcessesNamed"));
    G4int nbOfProcess = fPm->GetVectorLength(GetFullParmName("ProcessesNamed"));
    fParticlesToBias = fPm->GetStringVector(GetFullParmName("ParticlesNamed"));
    fNbOfParticles = fPm->GetVectorLength(GetFullParmName("ParticlesNamed"));
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
	
    for ( int i = 0; i < nbOfProcess; i++ )
        fProcessToBias.push_back(fProcessesToBias[i]);
}


void TsInelasticSplitManager::Initialize() {
	SetGenericBiasing();
}


void TsInelasticSplitManager::SetGenericBiasing() {
	return;
}


G4GenericBiasingPhysics* TsInelasticSplitManager::GetGenericBiasingPhysics() {
	G4GenericBiasingPhysics* biasingPhysics = new G4GenericBiasingPhysics();
	for ( int i = 0; i < fNbOfParticles; i++ )
		biasingPhysics->PhysicsBias(fParticlesToBias[i], fProcessToBias);
	
    return biasingPhysics;
}


void TsInelasticSplitManager::Clear() {
	return;
}
