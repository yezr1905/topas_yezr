#include "TsFilterByRTStructure.hh"

#include "TsVGeometryComponent.hh"
#include "TsVScorer.hh"

TsFilterByRTStructure::TsFilterByRTStructure(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
										   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert) {
	fStructureIDs = new std::vector<G4int>;
	ResolveParameters();

	// Scorer will need a pointer back to this filter to get StructureIDs at output time
	fScorer->SetRTStructureFilter(this);
}


TsFilterByRTStructure::~TsFilterByRTStructure()
{;}


void TsFilterByRTStructure::ResolveParameters() {
	fNames = fPm->GetStringVector(GetFullParmName(GetName()));
	fNamesLength = fPm->GetVectorLength(GetFullParmName(GetName()));

	CacheGeometryPointers();
}


void TsFilterByRTStructure::CacheGeometryPointers() {
	fStructureIDs->clear();

	fComponent = fScorer->GetComponent();

	for (G4int i = 0; i < fNamesLength; i++) {
		G4int j = fComponent->GetStructureID(fNames[i]);
		if (j==-1) {
			G4cerr << "Topas is exiting due to a serious error in scorer setup." << G4endl;
			G4cerr << "Component: " << fComponent->GetNameWithCopyId() << " does not have stucture: " << fNames[i] << G4endl;
			fPm->AbortSession(1);
		}
		fStructureIDs->push_back(j);
	}
}


G4bool TsFilterByRTStructure::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	// See if this index number is in any of the specified structures
	for (G4int i = 0; i < (int)fStructureIDs->size(); i++) {
		if (fComponent->IsInNamedStructure((*fStructureIDs)[i], aStep)) {
			if (fInvert) return false;
			else return true;
		}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByRTStructure::AcceptTrack(const G4Track*) const {
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}


std::vector<G4int>* TsFilterByRTStructure::GetStructureIDs() {
	return fStructureIDs;
}


G4bool TsFilterByRTStructure::IsInverted() {
	return fInvert;
}
