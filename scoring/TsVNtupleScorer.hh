#ifndef TsVNtupleScorer_hh
#define TsVNtupleScorer_hh

#include "TsVScorer.hh"
#include "TsVNtuple.hh"

class TsVNtupleScorer : public TsVScorer
{
public:
	TsVNtupleScorer(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsScoringManager* scM,
					G4String scorerName, G4String quantity, G4String outFileName, G4bool isSubScorer);

	virtual ~TsVNtupleScorer();

	void PostConstructor();
	void RestoreResultsFromFile();
	void AccumulateEvent();
	void AbsorbResultsFromWorkerScorer(TsVScorer* workerScorer);
	virtual void Output();
	virtual void Clear();

protected:
	TsVNtuple *fNtuple;
};

#endif
