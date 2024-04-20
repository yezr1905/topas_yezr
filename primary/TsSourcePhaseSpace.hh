#ifndef TsSourcePhaseSpace_hh
#define TsSourcePhaseSpace_hh

#include "TsSource.hh"

#include "TsPrimaryParticle.hh"

#include <queue>
#include <fstream>

class TsSourcePhaseSpace : public TsSource
{
public:
	TsSourcePhaseSpace(TsParameterManager* pM, TsSourceManager* psM, G4String sourceName);
	~TsSourcePhaseSpace();

	void ResolveParameters();

	void ReadSomeDataFromFileToBuffer(std::queue<TsPrimaryParticle>* particleBuffer);

    G4bool ReadOneParticle(std::queue<TsPrimaryParticle>* particleBuffer);

    G4long GetFileSize(std::string filename);

private:
	G4String fFileName;
    G4int fRecordLength;
    G4long fFileSize;
    std::ifstream fDataFile;
    std::streampos fFilePosition;
    G4String fAsciiLine;
    G4bool fIgnoreUnsupportedParticles;
    G4bool fIncludeEmptyHistories;
	G4long fNumberOfEmptyHistoriesToAppend;
	G4long fNumberOfEmptyHistoriesAppended;
    G4bool fPreviousHistoryWasEmpty;
	G4int fMultipleUse;
	G4bool fIsBinary;
	G4bool fIsLimited;
	G4bool fLimitedHasZ;
	G4bool fLimitedHasWeight;
	G4bool fLimitedAssumePhotonIsNewHistory;
	G4bool fLimitedAssumeEveryParticleIsNewHistory;
	G4bool fLimitedAssumeFirstParticleIsNewHistory;
    G4bool fPreCheck;
    G4long fPreCheckNumberOfHistories;
    G4long fPreCheckNumberOfNonEmptyHistories;
    G4long fPreCheckNumberOfParticles;
	G4int fPreCheckShowParticleCountAtInterval;
    G4long fHeaderNumberOfHistories;
	G4long fHeaderNumberOfNonEmptyHistories;
	G4long fHeaderNumberOfParticles;
	G4double fPhaseSpaceScaleXPosBy;
	G4double fPhaseSpaceScaleYPosBy;
	G4double fPhaseSpaceScaleZPosBy;
	G4bool fPhaseSpaceInvertXAxis;
	G4bool fPhaseSpaceInvertYAxis;
	G4bool fPhaseSpaceInvertZAxis;
    TsPrimaryParticle fPrimaryParticle;
};

#endif
