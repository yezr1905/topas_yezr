#ifndef TsTFSine_hh
#define TsTFSine_hh

#include "TsVTimeFunction.hh"

class TsTFSine : public TsVTimeFunction {
private:
		G4double fA;
		G4double fB;
public:
	 TsTFSine(G4double , G4double);
	~TsTFSine();
	virtual G4double operator()(G4double t);
};
#endif
