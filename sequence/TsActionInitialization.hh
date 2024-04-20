#ifndef TsActionInitialization_hh
#define TsActionInitialization_hh

#include "TsTopasConfig.hh"

#ifdef TOPAS_MT
#include "G4VUserActionInitialization.hh"
#endif

class TsParameterManager;
//class TsExtensionManager;
class TsGeometryManager;
class TsSourceManager;
class TsFilterManager;
//class TsChemistryManager;
class TsVarianceManager;
class TsSequenceManager;

#ifdef TOPAS_MT
class TsActionInitialization : public G4VUserActionInitialization
#else
class TsActionInitialization
#endif
{
  public:
	//TsActionInitialization(TsParameterManager* pM, TsExtensionManager* eM,
	//					   TsGeometryManager* gM, TsSourceManager* soM,
	//					   TsFilterManager* fM, TsChemistryManager* chM,
	//					   TsVarianceManager* vM, TsSequenceManager* sqM);
	TsActionInitialization(TsParameterManager* pM,
		TsGeometryManager* gM, TsSourceManager* soM,
		TsFilterManager* fM,
		TsVarianceManager* vM, TsSequenceManager* sqM);
	virtual ~TsActionInitialization();

	virtual void Build() const;

private:
	TsParameterManager* fPm;
	//TsExtensionManager* fEm;
	TsGeometryManager*  fGm;
	TsSourceManager*    fSom;
	TsFilterManager*	fFm;
	//TsChemistryManager*	fChm;
	TsVarianceManager*  fVm;
	TsSequenceManager*	fSqm;
};

#endif
