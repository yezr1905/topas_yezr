#include "TsVBiasingProcess.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

TsVBiasingProcess::TsVBiasingProcess(G4String name, TsParameterManager* pM, TsGeometryManager* )
:fPm(pM), fName(name), fHadParameterChangeSinceLastRun(false)
{
	fVerbosity = fPm->GetIntegerParameter("Ts/SequenceVerbosity");
	if (fVerbosity>0)
		G4cout << "Registering biasing technique: " << fName << G4endl;
	
	ResolveParameters();
}


TsVBiasingProcess::~TsVBiasingProcess()
{;}


void TsVBiasingProcess::UpdateForSpecificParameterChange(G4String parameter) {
	if (fVerbosity>0)
		G4cout << "TsVBiasingProcess::UpdateForSpecificParameterChange for biasing: "
		<< fName << " called for parameter: " << parameter << G4endl;
	
	fHadParameterChangeSinceLastRun = true;
}


void TsVBiasingProcess::UpdateForNewRun(G4bool rebuiltSomeComponents) {
	if (fVerbosity>0)
		G4cout << "TsVBiasingProcess::UpdateForNewRun for biasing: "
		<< GetName() << " called with fHadParameterChangeSinceLastRun: "
		<< fHadParameterChangeSinceLastRun << ", rebuiltSomeComponents: "
		<< rebuiltSomeComponents << G4endl;
	
	if (fHadParameterChangeSinceLastRun) {
		ResolveParameters();
		fHadParameterChangeSinceLastRun = false;
	}
}


void TsVBiasingProcess::ResolveParameters() {
	if (fVerbosity>0)
		G4cout << "TsVBiasingProcess::ResolveParameters" << G4endl;
	
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
}


void TsVBiasingProcess::AddBiasingProcess() {
	if (fVerbosity>0)
		G4cout << "TsVBiasingProcess:AddBiasingProcess" << G4endl;
}


void TsVBiasingProcess::Clear() {
	if (fVerbosity>0)
		G4cout << "TsVBiasingProcess:Clear" << G4endl;
}


void TsVBiasingProcess::Initialize() {
	if (fVerbosity>0)
		G4cout << "TsVBiasingProcess::Initialize" << G4endl;
}


G4String TsVBiasingProcess::GetFullParmName(G4String parmName) {
	G4String fullName = "Vr/" + fName + "/" + parmName;
	return fullName;
}


void TsVBiasingProcess::Quit(const G4String& name, G4String message) {
	G4cerr << "Topas is exiting due to a serious error in geometry setup." << G4endl;
	G4cerr << "Parameter name: " << name << G4endl;
	G4cerr << message << G4endl;
	fPm->AbortSession(1);
}
