#ifndef TsTFExponent_hh
#define TsTFExponent_hh

#include "TsVTimeFunction.hh"
#include <cmath>

class TsTFExponent : public TsVTimeFunction {
private:
		G4double fA;
		G4double fB;
public:
	 TsTFExponent(G4double , G4double);
	~TsTFExponent();
	virtual G4double operator()(G4double t);
};

#endif
