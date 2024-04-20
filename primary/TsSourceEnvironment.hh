#ifndef TsSourceEnvironment_hh
#define TsSourceEnvironment_hh

#include "TsSource.hh"

class TsSourceEnvironment : public TsSource
{
public:
	TsSourceEnvironment(TsParameterManager* pM, TsSourceManager* psM, G4String sourceName);
	~TsSourceEnvironment();

	void UpdateForEndOfRun();

private:
	G4double fAccumulatedFluence;
};

#endif
