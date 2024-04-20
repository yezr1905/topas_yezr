#ifndef TsScoringHub_hh
#define TsScoringHub_hh

#include "globals.hh"

class TsParameterManager;
//class TsExtensionManager;
class TsMaterialManager;
class TsGeometryManager;
class TsScoringManager;

class TsVScorer;

class TsScoringHub
{
public:
	TsScoringHub(TsParameterManager* pM);
	~TsScoringHub();

	//TsVScorer* InstantiateScorer(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM,
	//							 TsScoringManager* scM, G4String scorerName, G4String quantityName,
	//							 G4String outFileName, G4bool isSubScorer);
	TsVScorer* InstantiateScorer(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
		TsScoringManager* scM, G4String scorerName, G4String quantityName,
		G4String outFileName, G4bool isSubScorer);

	//void AddScorerFromGUI(G4String& scorerName, G4String& componentName, G4String& quantityName);

private:
	TsParameterManager* fPm;
};
#endif
