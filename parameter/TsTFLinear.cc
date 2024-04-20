#include "TsTFLinear.hh"

TsTFLinear::TsTFLinear(G4double a, G4double b) : fA(a), fB(b) {;}
TsTFLinear::~TsTFLinear() {;}

inline G4double TsTFLinear::operator()(G4double t) {
		return (fA*t + fB);
}
