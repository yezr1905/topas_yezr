#ifndef TsSourcePhaseSpaceOld_hh
#define TsSourcePhaseSpaceOld_hh

#include "TsSource.hh"

#include "TsPrimaryParticle.hh"

#include <queue>

class TsSourcePhaseSpaceOld : public TsSource
{
public:
	TsSourcePhaseSpaceOld(TsParameterManager* pM, TsSourceManager* psM, G4String sourceName);
	~TsSourcePhaseSpaceOld();

	void ResolveParameters();

	G4long GetNumberOfHistoriesToReadFromFile();

	// Returns True if there is still more data in file
	G4bool ReadSomeDataFromFileToBuffer(std::queue<TsPrimaryParticle>* particleBuffer);

private:
	G4String fFileName;
	G4bool fIsBinary;
	G4bool fIsLimited;
	G4bool fLimitedHasZ;
	G4bool fLimitedHasWeight;
	G4bool fLimitedAssumePhotonIsNewHistory;
	G4int fRecordLength;
	G4long fNumberOfOriginalHistories;
	G4long fNumberOfHistoriesInFile;
	G4long fNumberOfParticlesInFile;
	G4long fPreCheckNumberOfParticlesInFile;
	G4long fPreCheckNumberOfHistoriesInFile;
	G4int fMultipleUse;
	G4long fNumberOfHistoriesToReadFromFile;
	G4long fRemainingNumberOfParticlesInFile;
	G4long fPhaseSpaceBufferSize;
	G4double fPhaseSpaceScaleXPosBy;
	G4double fPhaseSpaceScaleYPosBy;
	G4double fPhaseSpaceScaleZPosBy;
	G4bool fPhaseSpaceInvertXAxis;
	G4bool fPhaseSpaceInvertYAxis;
	G4bool fPhaseSpaceInvertZAxis;
	G4bool fIgnoreUnsupportedParticles;
	G4bool fIncludeEmptyHistories;
	G4bool fPreCheck;

	std::streampos fFilePosition;
};

#endif
