#include "TsPhotoNeutron.hh"

#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4HadronInelasticProcess.hh"
#include "G4LENDorBERTModel.hh"
#include "G4LENDCombinedCrossSection.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhotoNuclearCrossSection.hh"

// factory
#include "G4PhysicsConstructorFactory.hh"
//
G4_DECLARE_PHYSCONSTR_FACTORY(TsPhotoNeutron);

TsPhotoNeutron::TsPhotoNeutron(TsParameterManager*)
  : G4VPhysicsConstructor("PhotoNeutron")
{}


TsPhotoNeutron::TsPhotoNeutron(G4int)
: G4VPhysicsConstructor("PhotoNeutron")
{}


TsPhotoNeutron::~TsPhotoNeutron()
{}


void TsPhotoNeutron::ConstructProcess()
{
   G4ProcessManager* pManager = G4Gamma::Gamma()->GetProcessManager();
   G4HadronInelasticProcess* process = new G4HadronInelasticProcess("photonNuclear", G4Gamma::Definition());
   process->AddDataSet(new G4PhotoNuclearCrossSection);

   G4LENDorBERTModel* LEND = new G4LENDorBERTModel(G4Gamma::Gamma());
   LEND->SetMaxEnergy(40*MeV);
   process->RegisterMe(LEND);

   G4LENDCombinedCrossSection* LENDXS = new G4LENDCombinedCrossSection(G4Gamma::Gamma());
   LENDXS->SetMaxKinEnergy(40*MeV);
   LENDXS->DumpLENDTargetInfo(true);
   process->AddDataSet(LENDXS);

   pManager->AddDiscreteProcess(process);      
}

