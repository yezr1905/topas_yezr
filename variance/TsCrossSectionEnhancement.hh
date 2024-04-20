#ifndef CrossSectionEnhancement_hh
#define CrossSectionEnhancement_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsCrossSectionEnhancement : public TsVBiasingProcess
{
public:
	TsCrossSectionEnhancement(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsCrossSectionEnhancement();
	
	void ResolveParameters();
	void Initialize();
	void Clear();
	void SetCrossSectionEnhancement();
	void AddBiasingProcess() {return;};
	
private:
	TsParameterManager* fPm;
	G4String fName;
	std::vector<G4String> fProcesses;
	std::vector<G4double> fFactors;
};
#endif
