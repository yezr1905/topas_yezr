#ifndef TsVTimeFunction_hh
#define TsVTimeFunction_hh

#include "globals.hh"

class TsVTimeFunction{
public:
	 TsVTimeFunction();
	~TsVTimeFunction();
	virtual G4double operator()(G4double) {return 0.0;};
};

#endif
