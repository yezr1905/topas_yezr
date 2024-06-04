#ifndef TsFilterByInteractedOrTraversed_hh
#define TsFilterByInteractedOrTraversed_hh

#include "TsVFilter.hh"

class G4VPhysicalVolume;

class TsFilterByInteractedOrTraversed : public TsVFilter
{
public:
	TsFilterByInteractedOrTraversed(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
									TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert,
					 G4bool includeAncestors, G4bool namesAreVolumes,
					 G4bool includeChildren, G4bool testTraversed,
					 G4bool onlyConsiderLastVolume);
	virtual ~TsFilterByInteractedOrTraversed();

	void ResolveParameters();
	void CacheGeometryPointers();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

private:
	G4bool fIncludeAncestors;
	G4bool fNamesAreVolumes;
	G4bool fIncludeChildren;
	G4bool fTestTraversed;
	G4bool fOnlyConsiderLastVolume;
	G4String* fNames;
	G4int fNamesLength;
	std::vector<G4VPhysicalVolume*> fVolumes;
};
#endif

