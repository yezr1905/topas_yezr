#ifndef TsGeneratorEmittance_hh
#define TsGeneratorEmittance_hh

#include "TsVGenerator.hh"

#include "G4PhysicalConstants.hh"
#include "G4ThreeVector.hh"
#include "Randomize.hh"

#include <cmath>
#include <fstream>
//Expecting users to give alpha, beta, emittance.
//Alpha can be 0 but beta and emittance can't be zero
//Gamma is internally calculated

class TsTwissParameters
{
private:
	G4double gamma;
	G4double alpha;
	G4double beta ;
	G4double emittance;
	G4String name;

public:
	 TsTwissParameters(G4String n): gamma(0), alpha(0), beta(0), emittance(0), name(n) {;}
	~TsTwissParameters() {;}

	inline void SetParameters(G4double a, G4double b, G4double e){
		if( e <= 0.0 || b <= 0.0 ){
			G4cerr << "Topas is exiting due to a serious error in beam source setup.. " << G4endl;
				G4cerr << "Emittance and Beta can't be less than zero: " << name << G4endl;
			exit(1);
		}
		alpha = a; beta = b; emittance = e; gamma = (1.0 + alpha*alpha)/beta;
	}

	inline void Gaussian(G4double& prob, G4double& u, G4double& v){
		u = G4RandGauss::shoot(0.0,prob);
		v = G4RandGauss::shoot(0.0,prob);
	}

	inline void KV(G4double& prob, G4double& u, G4double& v){
		//For given prob, return u and v
		G4double th =CLHEP::twopi*G4UniformRand();
		u = std::sqrt(prob)*cos(th);
		v = std::sqrt(prob)*sin(th);
	}

	inline void Transform(G4double& u, G4double& v, G4float& x, G4double& xp){
		//For given u and v, update x and xp
		x  = std::sqrt(beta*emittance)*u;
		xp = std::sqrt(emittance/beta)*v - (alpha/beta)*x;
	}

};

class TsGeneratorEmittance : public TsVGenerator
{
public:
	TsGeneratorEmittance(TsParameterManager* pM, TsGeometryManager* gM, TsGeneratorManager* psM, G4String sourceName);
	~TsGeneratorEmittance();

	void ResolveParameters();

	void GeneratePrimaries(G4Event*);

private:
	G4String fEmittanceDistName;
	enum  emittance_distribution {BiGaussian, TWISS_kv, TWISS_gaussian, TWISS_wb} fEmittanceDistType;
	//For BiGaussian
	G4double fSigX, fSigXprime;
	G4double fSigY, fSigYprime;
	G4double fRhoX, fRhoY ; //correlation

	//For Twiss
	TsTwissParameters fTwissX;
	TsTwissParameters fTwissY;
	//Twiss Gaussians ONLY
	G4double fFractionX;
	G4double fFractionY;

	enum Shape { ELLIPSE, RECTANGLE, NONE };
	Shape fBeamShape;
	G4double fPositionCutoffX;
	G4double fPositionCutoffY;
};

#endif
