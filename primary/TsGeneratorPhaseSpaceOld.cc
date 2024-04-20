#include "TsGeneratorPhaseSpaceOld.hh"

#include "TsSourcePhaseSpaceOld.hh"

TsGeneratorPhaseSpaceOld::TsGeneratorPhaseSpaceOld(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName) :
TsVGenerator(pM, gM, pgM, sourceName)
{
	fParticleBuffer = new std::queue<TsPrimaryParticle>;

	ResolveParameters();
	CacheGeometryPointers();
}


TsGeneratorPhaseSpaceOld::~TsGeneratorPhaseSpaceOld()
{
}


void TsGeneratorPhaseSpaceOld::ResolveParameters() {
	fNumberOfHistoriesToReadFromFile = ((TsSourcePhaseSpaceOld*)fPs)->GetNumberOfHistoriesToReadFromFile();
}


void TsGeneratorPhaseSpaceOld::UpdateForNewRun(G4bool rebuiltSomeComponents) {
	TsVGenerator::UpdateForNewRun(rebuiltSomeComponents);
	ResolveParameters();
}


void TsGeneratorPhaseSpaceOld::ClearGenerator() {
	while(!fParticleBuffer->empty())
		fParticleBuffer->pop();
}


void TsGeneratorPhaseSpaceOld::GeneratePrimaries(G4Event* anEvent)
{
	if (CurrentSourceHasGeneratedEnough())
		return;

	// If we still need to generate histories, but we have already generated the full number that we
	// intended to generate from the file, then we are being asked to generate an Empty History
	if (fHistoriesGeneratedInRun > fNumberOfHistoriesToReadFromFile) {
		G4cout << "Generate an Empty History" << G4endl;
	} else {
		// Generate all of particles in the current history.
		// Depending on upstream interactions, this may or may not contain the original primary,
		// and this may or may not contain some number of secondaries.
		// The first particle we encounter is guaranteed to have the IsNewHistory flag
		// (since our previous loop will have used up all the particles from the previous history).
		// We keep looping until we find another IsNewHistory or we hit the end of the file.
		G4bool alreadyHadNewHistoryInThisGeneratePrimaries = false;

		G4bool stillMoreDataInFile = true;
		G4bool generateAnother = true;
		while ( generateAnother ) {
			// If the buffer is empty, we read more particles from the file.
			if (fParticleBuffer->empty())
				stillMoreDataInFile = ((TsSourcePhaseSpaceOld*)fPs)->ReadSomeDataFromFileToBuffer(fParticleBuffer);

			// Examine the next particle in the buffer
			TsPrimaryParticle p = fParticleBuffer->front();

			// If this is a new history, and we've already seen a new history in this GeneratePrimaries,
			// don't use it now. It will belong to the next GeneratePrimaries.
			if (p.isNewHistory && alreadyHadNewHistoryInThisGeneratePrimaries)
				generateAnother = false;
			else {
				TransformPrimaryForComponent(&p);
				GenerateOnePrimary(anEvent, p);
				fParticleBuffer->pop();
				alreadyHadNewHistoryInThisGeneratePrimaries = true;
				if (fParticleBuffer->empty() && (!stillMoreDataInFile))
					generateAnother = false;
			}
		}

		AddPrimariesToEvent(anEvent);
	}
}
