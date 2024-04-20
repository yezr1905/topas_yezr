#include "TsGeneratorIsotropic.hh"

#include "TsParameterManager.hh"

#include "G4PhysicalConstants.hh"
#include "Randomize.hh"

TsGeneratorIsotropic::TsGeneratorIsotropic(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName) :
TsVGenerator(pM, gM, pgM, sourceName)
{
	ResolveParameters();
}


TsGeneratorIsotropic::~TsGeneratorIsotropic()
{
}


void TsGeneratorIsotropic::ResolveParameters() {
	TsVGenerator::ResolveParameters();
}


void TsGeneratorIsotropic::GeneratePrimaries(G4Event* anEvent)
{
	if (CurrentSourceHasGeneratedEnough())
		return;

	TsPrimaryParticle p;

	G4double costheta = G4RandFlat::shoot( -1., 1);
	G4double sintheta = sqrt(1. - costheta*costheta);
	G4double phi = 2.* CLHEP::pi * G4UniformRand();
	G4double sinphi = sin(phi);
	G4double cosphi = cos(phi);
	G4double px = sintheta * cosphi;
	G4double py = sintheta * sinphi;
	G4double pz = costheta;
	G4double mag = std::sqrt((px*px) + (py*py) + (pz*pz));

	p.dCos1 = px / mag;
	p.dCos2 = py / mag;
	p.dCos3 = pz / mag;
	p.posX = 0.;
	p.posY = 0.;
	p.posZ = 0.;

	SetEnergy(p);
	SetParticleType(p);

	p.weight = 1.;
	p.isNewHistory = true;

	TransformPrimaryForComponent(&p);
	GenerateOnePrimary(anEvent, p);
	AddPrimariesToEvent(anEvent);
}
