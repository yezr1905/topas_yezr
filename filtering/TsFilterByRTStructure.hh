#ifndef TsFilterByRTStructure_hh
#define TsFilterByRTStructure_hh

#include "TsVFilter.hh"

class TsVGeometryComponent;

class TsFilterByRTStructure : public TsVFilter
{
public:
	TsFilterByRTStructure(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
						 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert);
	virtual ~TsFilterByRTStructure();

	void ResolveParameters();
	void CacheGeometryPointers();

	virtual G4bool Accept(const G4Step*) const;
	virtual G4bool AcceptTrack(const G4Track*) const;

	std::vector<G4int>* GetStructureIDs();
	G4bool IsInverted();

private:
	G4String* fNames;
	G4int fNamesLength;
	std::vector<G4int>* fStructureIDs;
	TsVGeometryComponent* fComponent;
};
#endif

