#include "TsCrossSectionEnhancement.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"

#include <vector>

TsCrossSectionEnhancement::TsCrossSectionEnhancement(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name)
{
	ResolveParameters();
}


TsCrossSectionEnhancement::~TsCrossSectionEnhancement()
{;}


void TsCrossSectionEnhancement::ResolveParameters() {
	G4String* processes = fPm->GetStringVector(GetFullParmName("ProcessesNamed"));
	G4double* factors = fPm->GetUnitlessVector(GetFullParmName("EnhancementFactor"));
	G4int nbOfProcesses = fPm->GetVectorLength(GetFullParmName("ProcessesNamed"));
	
	if ( nbOfProcesses != fPm->GetVectorLength(GetFullParmName("EnhancementFactor")))
		Quit(GetFullParmName("ProcessesNamed"),
			 "size does not match with size of parameter named: " +
			 GetFullParmName("EnhancementFactor"));
	
	for ( int i = 0; i < nbOfProcesses; i++) {
		fProcesses.push_back(processes[i]);
		fFactors.push_back(factors[i]);
	}
}


void TsCrossSectionEnhancement::Initialize() {
	SetCrossSectionEnhancement();
}


void TsCrossSectionEnhancement::SetCrossSectionEnhancement() {
	for ( size_t u = 0; u < fProcesses.size(); u++) {
		G4UImanager::GetUIpointer()->ApplyCommand("/process/em/setBiasingFactor " +
												  fProcesses[u] + " " +
												  G4UIcommand::ConvertToString(fFactors[u]) +
												  " true ");
		G4cout << "Cross-section enhancement of process " << fProcesses[u]
		       << " by a factor of " << fFactors[u] << G4endl;
	}
}


void TsCrossSectionEnhancement::Clear() {
	fProcesses.clear();
	fFactors.clear();
}
