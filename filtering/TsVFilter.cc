#include "TsVFilter.hh"

#include "TsMaterialManager.hh"
#include "TsGeometryManager.hh"
#include "TsFilterManager.hh"

TsVFilter::TsVFilter(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
					 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
:G4VSDFilter(name), fInvert(invert), fPm(pM), fGenerator(generator), fScorer(scorer), fParentFilter(parentFilter),
fMm(mM), fGm(gM), fFm(fM), fHadParameterChangeSinceLastRun(false)
{
	if (generator) {
		fFullName = generator->GetName() + "/" + name;
		fVerbosity = fPm->GetIntegerParameter("So/Verbosity");
	} else {
		fFullName = scorer->GetName() + "/" + name;
		fVerbosity = fPm->GetIntegerParameter("Sc/Verbosity");
	}

	if (GetName() == "PseudoFilter")
		fVerbosity = 0;

	if (fVerbosity>0)
		G4cout << "Registering filter: " << fFullName << G4endl;

	fFm->SetCurrentFilter(this);

	ResolveParameters();
}


TsVFilter::~TsVFilter()
{;}


void TsVFilter::UpdateForSpecificParameterChange(G4String parameter) {
	if (fVerbosity>0)
		G4cout << "TsVFilter::UpdateForSpecificParameterChange for filter: " << GetFullName() << " called for parameter: " << parameter << G4endl;
	fHadParameterChangeSinceLastRun = true;
}


void TsVFilter::UpdateForNewRun(G4bool rebuiltSomeComponents) {
	if (fVerbosity>0)
		G4cout << "TsVFilter::UpdateForNewRun for filter: " << GetFullName() << " called with fHadParameterChangeSinceLastRun: " <<
		fHadParameterChangeSinceLastRun << ", rebuiltSomeComponents: " << rebuiltSomeComponents << G4endl;

	if (fHadParameterChangeSinceLastRun) {
		ResolveParameters();
		fHadParameterChangeSinceLastRun = false;
	} else if (rebuiltSomeComponents)
		CacheGeometryPointers();
}


G4String TsVFilter::GetFullParmName(const char* parm) {
	if (fGenerator)
		return fGenerator->GetFullParmName(parm);
	else
		return fScorer->GetFullParmName(parm);
}


G4String TsVFilter::GetFullName() {
	return fFullName;
}


void TsVFilter::ResolveParameters() {
}


void TsVFilter::CacheGeometryPointers() {
}


G4VPhysicalVolume* TsVFilter::GetPhysicalVolume(G4String volumeName) {
	return fGm->GetPhysicalVolume(volumeName);
}


TsVGeometryComponent* TsVFilter::GetComponent(G4String& nameWithCopyId) {
	return fGm->GetComponent(nameWithCopyId);
}


std::vector<G4String> TsVFilter::GetChildComponentsOf(G4String& parentName) {
	return fGm->GetChildComponentsOf(parentName);
}


G4Material* TsVFilter::GetMaterial(G4String name) {
	return fMm->GetMaterial(name);
}


G4Material* TsVFilter::GetMaterial(const char* c) {
	return fMm->GetMaterial(c);
}
