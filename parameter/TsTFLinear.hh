#ifndef TsTFLinear_hh
#define TsTFLinear_hh

#include "TsVTimeFunction.hh"

class TsTFLinear : public TsVTimeFunction {
private:
		const G4double fA;
		const G4double fB;
public:
	 TsTFLinear(G4double , G4double);
	~TsTFLinear();
	virtual G4double operator()(G4double t);
};

#endif
