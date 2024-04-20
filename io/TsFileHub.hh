#ifndef TsFileHub_hh
#define TsFileHub_hh

#include "globals.hh"

class TsParameterManager;
class TsScoringManager;
class TsExtensionManager;

class TsVFile;

class TsFileHub
{
public:
	TsFileHub(TsScoringManager* scM);
	~TsFileHub();

	TsVFile* InstantiateFile(TsParameterManager* pM,
							   G4String fileName, G4String fileMode, G4String fileType,
							   TsVFile *masterFile);

private:
	TsScoringManager* fScm;
};

#endif
