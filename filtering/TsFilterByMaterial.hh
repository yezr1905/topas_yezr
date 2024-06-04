#ifndef TsFilterByMaterial_hh
#define TsFilterByMaterial_hh

#include "TsVFilter.hh"

class G4Material;

class TsFilterByMaterial : public TsVFilter
{
public:
	TsFilterByMaterial(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
					   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert);
	virtual ~TsFilterByMaterial();

	void ResolveParameters();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	std::vector<G4Material*> fMaterials;
};
#endif
