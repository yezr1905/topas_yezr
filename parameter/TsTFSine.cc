#include "TsTFSine.hh"

#include <cmath>

TsTFSine::TsTFSine(G4double a, G4double b) : fA(a), fB(b) {;}
TsTFSine::~TsTFSine() {;}

inline G4double TsTFSine::operator()(G4double t) {
		return std::sin(fA*t+fB);
}
