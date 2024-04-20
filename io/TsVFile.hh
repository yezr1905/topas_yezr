#ifndef TsVFile_hh
#define TsVFile_hh

#include "TsParameterManager.hh"
#include "TsTopasConfig.hh"

#include "globals.hh"

class TsVFile
{
public:
	TsVFile(TsParameterManager* pM, G4String fileName, G4String mode, TsVFile *masterFile);
	~TsVFile();

	virtual void SetFileName(G4String newBaseFileName);

	G4bool HasHeaderFile() const { return fHasHeader; }
	G4String GetHeaderFileName() const { return fPathHeader; }
	G4String GetDataFileName() const { return fPathData; }
	virtual void ConfirmCanOpen();

	G4String fHeaderText;

protected:
	void SetFileExtensions(G4String extData, G4String extHeader="");

	TsParameterManager* fPm;
	TsVFile *fMasterFile;

	enum FileMode { OVERWRITE, INCREMENT, EXIT } fMode;
	G4bool fIsPathUpdated;
	G4bool fHasHeader;

	G4String fBaseFileName;  // path without extension or increment
	G4String fExtensionData;
	G4String fExtensionHeader;
	G4String fPathData;
	G4String fPathHeader;

private:
	void SetFileName(G4String newBaseFileName, G4int increment);
	bool IsWriteable(G4String filePath) const;
	bool FileExists(G4String filePath) const;
};

#endif
