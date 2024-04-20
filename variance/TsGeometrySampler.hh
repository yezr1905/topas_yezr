#ifndef TsGeometrySampler_hh
#define TsGeometrySampler_hh TsGeometrySampler_hh

#include "G4Types.hh"
#include "G4String.hh"
#include "G4VSampler.hh"
#include "G4VSamplerConfigurator.hh"

class TsParameterManager;
class TsGeometryManager;
class TsSplitConfigurator;
class TsIStore;

class G4ImportanceConfigurator;
class G4WeightWindowConfigurator;
class G4WeightCutOffConfigurator;

class TsGeometrySampler : public G4VSampler
{
public:
	explicit TsGeometrySampler(TsParameterManager* pm, TsGeometryManager* gm, G4String worldvolumeName, const G4String &particlename);
	
	virtual ~TsGeometrySampler();
	
	virtual void PrepareImportanceSampling(G4VIStore* ,
										   const G4VImportanceAlgorithm*);
	virtual void PrepareWeightRoulett(G4double ,
									  G4double ,
									  G4double );
	
	virtual void PrepareWeightWindow(G4VWeightWindowStore *,
									 G4VWeightWindowAlgorithm *,
									 G4PlaceOfAction );
	
	virtual void PrepareSplitSampling(TsIStore*);
	
	
	virtual void Configure();
	virtual void AddProcess();
	virtual void ClearSampling();
	virtual G4bool IsConfigured() const;
	
	void SetParallel(G4bool paraflag);
	void SetWorld(const G4VPhysicalVolume* world);
	void SetParticle(const G4String &particlename);
	
	inline G4String GetParticleName() {return fParticleName;};
	
private:
	TsGeometrySampler(const TsGeometrySampler&) = delete;
	TsGeometrySampler& operator=(const TsGeometrySampler&) = delete;
	
private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	TsSplitConfigurator *fSplitConfigurator;
	TsIStore* fIStore;
	
	G4Configurators fConfigurators;

	G4String fParticleName;
	G4String fWorldName;

	const G4VPhysicalVolume* fWorld;
	
	G4bool fIsConfigured;
	G4bool fParaFlag;
};
#endif
