#include "TsGeneratorDistributed.hh"

#include "TsParameterManager.hh"
#include "TsSourceDistributed.hh"

#include "G4RandomDirection.hh"

TsGeneratorDistributed::TsGeneratorDistributed(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* pgM, G4String sourceName) :
TsVGenerator(pM, gM, pgM, sourceName)
{
	ResolveParameters();
}


TsGeneratorDistributed::~TsGeneratorDistributed()
{
}


void TsGeneratorDistributed::GeneratePrimaries(G4Event* anEvent)
{
	if (CurrentSourceHasGeneratedEnough())
		return;

	std::vector<G4Point3D*>::iterator iter;
	for (iter=((TsSourceDistributed*)fPs)->fSampledPoints.begin(); iter!=((TsSourceDistributed*)fPs)->fSampledPoints.end(); iter++) {
		
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
		
		p.posX = (*iter)->x();
		p.posY = (*iter)->y();
		p.posZ = (*iter)->z();

		SetEnergy(p);
		SetParticleType(p);

		p.weight = 1.;
		p.isNewHistory = true;

		GenerateOnePrimary(anEvent, p);
	}
	AddPrimariesToEvent(anEvent);
}
