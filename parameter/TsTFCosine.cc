#include "TsTFCosine.hh"

TsTFCosine::TsTFCosine(G4double a, G4double b) : fA(a), fB(b) {;}
TsTFCosine::~TsTFCosine() {;}

inline G4double TsTFCosine::operator()(G4double t) {
		return std::cos(fA*t+fB);
}
