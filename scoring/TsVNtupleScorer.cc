#include "TsVNtupleScorer.hh"

#include "TsFileHub.hh"
#include "TsScoringManager.hh"
#include "TsVGeometryComponent.hh"

TsVNtupleScorer::TsVNtupleScorer(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
			  					 G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer)
: TsVScorer(pM, mM, gM, scM, scorerName, quantity, outFileName, isSubScorer)
{
#ifdef TOPAS_MT
	TsVNtupleScorer* masterScorer = dynamic_cast<TsVNtupleScorer*>(fScm->GetMasterScorerByID(fUID));
#else
	TsVNtupleScorer* masterScorer = this;
#endif

	// If this is the master scorer, then the master ntuple doesn't yet exist => pass null pointer instead
	TsVFile* masterFile = (masterScorer == this) ? NULL : masterScorer->fOutFile;

	TsFileHub fileHub(scM);
	fOutFile = fileHub.InstantiateFile(fPm, fOutFileName, fOutFileMode, fOutFileType, masterFile);
	fNtuple = dynamic_cast<TsVNtuple*>(fOutFile);
	if (!fNtuple) {
		G4cerr << "Topas is exiting due to a serious error in scoring setup." << G4endl;
		G4cerr << "The scorer named " << GetName() << " has unsupported OutputType: " << fOutFileType << G4endl;
		G4cerr << "Ntuple OutputType must be ASCII, Binary or ROOT." << G4endl;
		G4cerr << "Phasespace scorers can additionally be of Limited OutputType." << G4endl;
		fPm->AbortSession(1);
	}

	if (fPm->ParameterExists(GetFullParmName("OutputBufferSize")))
		fNtuple->SetBufferSize(fPm->GetIntegerParameter(GetFullParmName("OutputBufferSize")));

	G4String parmName = GetFullParmName("RepeatSequenceUntilSumGreaterThan");
	if (fPm->ParameterExists(parmName)) {
		G4cerr << "Topas is exiting due to a serious error in scoring." << G4endl;
		G4cerr << "The parameter name: " << parmName << " can not be used since this is an nTuple scorer." << G4endl;
		G4cerr << "It can only be used with binned scorers." << G4endl;
		fPm->AbortSession(1);
	}

	parmName = GetFullParmName("RepeatSequenceUntilStandardDeviationLessThan");
	if (fPm->ParameterExists(parmName)) {
		G4cerr << "Topas is exiting due to a serious error in scoring." << G4endl;
		G4cerr << "The parameter name: " << parmName << " can not be used since this is an nTuple scorer." << G4endl;
		G4cerr << "It can only be used with binned scorers." << G4endl;
		fPm->AbortSession(1);
	}

	parmName = GetFullParmName("RepeatSequenceUntilCountGreaterThan");
	if (fPm->ParameterExists(parmName)) {
		G4cerr << "Topas is exiting due to a serious error in scoring." << G4endl;
		G4cerr << "The parameter name: " << parmName << " can not be used since this is an nTuple scorer." << G4endl;
		G4cerr << "It can only be used with binned scorers." << G4endl;
		fPm->AbortSession(1);
	}
}


TsVNtupleScorer::~TsVNtupleScorer()
{;}


void TsVNtupleScorer::PostConstructor()
{
	TsVScorer::PostConstructor();

	UpdateFileNameForUpcomingRun();
	fNtuple->ConfirmCanOpen();  // catch potential problems before we run
}


void TsVNtupleScorer::RestoreResultsFromFile()
{
	G4cerr << "Topas is exiting due to a serious error in scoring." << G4endl;
	G4cerr << "Called RestoreResultsFromFile for Scorer name: " << GetName() << G4endl;
	G4cerr << "but this is an ntuple scorer" << G4endl;
	fPm->AbortSession(1);
}


void TsVNtupleScorer::AccumulateEvent()
{
	if (fHaveIncidentParticle) {
	    UserHookForEndOfIncidentParticle();
	    fHaveIncidentParticle = false;
	}

	UserHookForEndOfEvent();

	fScoredHistories++;
}


void TsVNtupleScorer::AbsorbResultsFromWorkerScorer(TsVScorer* workerScorer)
{
	TsVNtupleScorer* workerNtupleScorer = dynamic_cast<TsVNtupleScorer*>(workerScorer);
	fNtuple->AbsorbWorkerNtuple(workerNtupleScorer->fNtuple);

	// Absorb additional statistics
	fScoredHistories += workerNtupleScorer->fScoredHistories;

	// Clear additional statistics of worker scorer
	workerNtupleScorer->fScoredHistories = 0;
}


void TsVNtupleScorer::Output()
{
	// collect additional statistics
	std::ostringstream prefix;
	prefix << "Number of Original Histories: " << GetScoredHistories() << G4endl;
	prefix << "Number of Scored Entries: " << fNtuple->GetNumberOfEntries() << G4endl;

	// write to disk
	fNtuple->fHeaderPrefix = prefix.str();
	fNtuple->Write();

	// report additional statistics to stdout
	G4cout << G4endl;
	G4cout << "Scorer: " << GetNameWithSplitId() << G4endl;
	if (fNtuple->HasHeaderFile())
		G4cout << "Header   has been written to file: " << fNtuple->GetHeaderFileName() << G4endl;
	G4cout << "Contents has been written to file: " << fNtuple->GetDataFileName() << G4endl;
	if (fPm->ParameterExists(GetFullParmName("Surface")))
		G4cout << "Scored on surface: " << fComponent->GetName() << "/" << GetSurfaceName() << G4endl;
	else
		G4cout << "Scored in component: " << fComponent->GetName() << G4endl;

	UpdateFileNameForUpcomingRun();
}


void TsVNtupleScorer::Clear()
{
	fScoredHistories = 0;
}
