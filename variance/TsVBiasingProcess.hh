#ifndef TsVBiasingProcess_hh
#define TsVBiasingProcess_hh

#include "TsGeometryManager.hh"

class TsParameterManager;

class TsVBiasingProcess
{
public:
	TsVBiasingProcess(G4String name, TsParameterManager* pM, TsGeometryManager* gM);
	
	virtual ~TsVBiasingProcess();
	
protected:
	virtual void ResolveParameters();
	virtual void Quit(const G4String& name, G4String message);
	virtual G4String GetFullParmName(G4String parmName);

	TsParameterManager* fPm;
	
public:
	void UpdateForSpecificParameterChange(G4String parameter);
	void UpdateForNewRun(G4bool rebuiltSomeComponents);
	
	virtual void AddBiasingProcess();
	virtual void Clear();
	virtual void Initialize();
	
	virtual G4String GetName() { return fName;};
	virtual G4String GetTypeName() { return fType;};
	
private:
	G4String fName;
	G4String fType;
	G4bool fHadParameterChangeSinceLastRun;
	G4int fVerbosity;
};
#endif

