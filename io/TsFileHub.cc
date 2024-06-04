#include "TsFileHub.hh"

#include "TsParameterManager.hh"
#include "TsScoringManager.hh"
//#include "TsExtensionManager.hh"

#include "TsNtupleAscii.hh"
#include "TsNtupleBinary.hh"
//#include "TsNtupleRoot.hh"

//#include "g4analysis_defs.hh"


TsFileHub::TsFileHub(TsScoringManager* scM)
: fScm(scM)
{;}


TsFileHub::~TsFileHub()
{;}


TsVFile* TsFileHub::InstantiateFile(TsParameterManager* pM,
									  G4String fileName, G4String fileMode, G4String fileType,
									  TsVFile *masterFile)
{
#if GEANT4_VERSION_MAJOR >= 11
	G4StrUtil::to_lower(fileType);
#else
	fileType.toLower();
#endif

	if (fileType == "ascii") {
		return new TsNtupleAscii(pM, fileName, fileMode, masterFile);
	} else if (fileType == "binary" || fileType == "limited") {
		return new TsNtupleBinary(pM, fileName, fileMode, masterFile);
	//} else if (fileType == "root") {
	//	return new TsNtupleRoot(pM, fileName, fileMode, masterFile, fScm->GetRootAnalysisManager());
	} else return NULL;
}
