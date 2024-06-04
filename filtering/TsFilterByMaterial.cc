#include "TsFilterByMaterial.hh"

#include "TsMaterialManager.hh"

#include "G4Material.hh"

TsFilterByMaterial::TsFilterByMaterial(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
									   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert)
{
	ResolveParameters();
}


TsFilterByMaterial::~TsFilterByMaterial()
{;}


void TsFilterByMaterial::ResolveParameters() {
	fMaterials.clear();

	G4String* materialNames = fPm->GetStringVector(GetFullParmName(GetName()));
	G4int length = fPm->GetVectorLength(GetFullParmName(GetName()));

	for (G4int i = 0; i < length; i++)
		fMaterials.push_back(GetMaterial(materialNames[i]));

	TsVFilter::ResolveParameters();
}


G4bool TsFilterByMaterial::Accept(const G4Step* aStep) const
{
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	for (G4int i=0; i < (int)fMaterials.size(); i++)
		if (aStep->GetTrack()->GetMaterial() == fMaterials[i]) {
			if (fInvert) return false;
			else return true;
	    }

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByMaterial::AcceptTrack(const G4Track*) const
{
	G4cerr << "Topas is exiting due to a serious error in source setup." << G4endl;
	G4cerr << "Sources cannot be filtered by " << GetName() << G4endl;
	fPm->AbortSession(1);
	return false;
}
