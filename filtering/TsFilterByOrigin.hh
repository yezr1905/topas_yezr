#ifndef TsFilterByOrigin_hh
#define TsFilterByOrigin_hh

#include "TsVFilter.hh"

class G4VPhysicalVolume;

class TsFilterByOrigin : public TsVFilter
{
public:
	TsFilterByOrigin(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
					 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert,
					 G4bool includeAncestors, G4bool namesAreVolumes, G4bool includeChildren);
	virtual ~TsFilterByOrigin();

	void ResolveParameters();
	void CacheGeometryPointers();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4bool fIncludeAncestors;
	G4bool fNamesAreVolumes;
	G4bool fIncludeChildren;
	G4String* fNames;
	G4int fNamesLength;
	std::vector<G4VPhysicalVolume*> fVolumes;
};
#endif

