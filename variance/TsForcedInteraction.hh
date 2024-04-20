#ifndef TsForcedInteraction_hh
#define TsForcedInteraction_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsForcedInteraction : public TsVBiasingProcess
{
public:
	TsForcedInteraction(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsForcedInteraction();
	
	void ResolveParameters();
	void Initialize();
	void Clear();
	void SetForcedInteraction();
	void AddBiasingProcess() {return;};
	
private:
	TsParameterManager* fPm;
	
	G4String fName;
	std::vector<G4String> fRegionName;
};
#endif
