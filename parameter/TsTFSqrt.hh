#ifndef TsTFSqrt_hh
#define TsTFSqrt_hh

#include "TsVTimeFunction.hh"

class TsTFSqrt : public TsVTimeFunction{
private:
		G4double fA;
		G4double fB;
public:
	TsTFSqrt(G4double, G4double);
	~TsTFSqrt();
	virtual G4double operator()(G4double t);
};

#endif
