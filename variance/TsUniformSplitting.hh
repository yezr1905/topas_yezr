#ifndef TsUniformSplitting_hh
#define TsUniformSplitting_hh

#include "TsVBiasingProcess.hh"

#include <vector>

class TsParameterManager;
class TsGeometryManager;

class TsUniformSplitting : public TsVBiasingProcess
{
public:
	TsUniformSplitting(G4String name, TsParameterManager*, TsGeometryManager*);
	~TsUniformSplitting();

	void ResolveParameters();
	void AddBiasingProcess() { return; };
	void Initialize();
	void Clear();
	void SetUniformSplitting();

private:
	TsParameterManager* fPm;
	
	G4String fName;
	G4String fType;
	G4bool fUseDirectionalSplitting;
	std::vector<G4String> fRegionName;
	std::vector<G4String> fProcesses;
	std::vector<G4double> fSplitNumber;
	std::vector<G4double> fLowerEnergyLimitForRussianRoulette;
	G4double fTransX;
	G4double fTransY;
	G4double fTransZ;
	G4double fRMax;
};
#endif
