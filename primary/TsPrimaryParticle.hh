#ifndef TsPrimaryParticle_hh
#define TsPrimaryParticle_hh

#include "globals.hh"

class G4ParticleDefinition;

struct TsPrimaryParticle
{
	G4float posX;
	G4float posY;
	G4float posZ;
	G4float dCos1;
	G4float dCos2;
	G4float dCos3;
	G4float kEnergy;
	G4float weight;
	G4ParticleDefinition* particleDefinition;
	G4bool isNewHistory;
	G4bool isOpticalPhoton;
	G4bool isGenericIon;
	G4int ionCharge;
};

#endif
