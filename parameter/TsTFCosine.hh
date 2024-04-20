#ifndef TsTFCosine_hh
#define TsTFCosine_hh

#include "TsVTimeFunction.hh"
#include <cmath>

class TsTFCosine : public TsVTimeFunction {
private:
		G4double fA;
		G4double fB;
public:
	 TsTFCosine(G4double , G4double);
	~TsTFCosine();
	virtual G4double operator()(G4double t);
};

#endif
