#ifndef TsGeneratorBeam_hh
#define TsGeneratorBeam_hh

#include "TsVGenerator.hh"

class TsGeneratorBeam : public TsVGenerator
{
public:
	TsGeneratorBeam(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName);
	~TsGeneratorBeam();

	void ResolveParameters();

	void GeneratePrimaries(G4Event* );

private:
	void SetPosition(TsPrimaryParticle &p) const;
	void SetDirection(TsPrimaryParticle &p) const;
	G4float AngleToMarsagliaCoordinate(G4float angle) const;

	enum DistributionType { NONE, FLAT, GAUSSIAN };
	DistributionType fPositionDistribution;
	DistributionType fAngularDistribution;

	enum Shape { ELLIPSE, RECTANGLE };
	Shape fBeamShape;
	G4double fPositionCutoffX;
	G4double fPositionCutoffY;
	G4double fPositionSpreadX;
	G4double fPositionSpreadY;
	G4double fMarsagliaCutoffX;
	G4double fMarsagliaCutoffY;
	G4double fMarsagliaSpreadX;
	G4double fMarsagliaSpreadY;
};

#endif
