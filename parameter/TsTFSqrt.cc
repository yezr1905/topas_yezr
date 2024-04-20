#include "TsTFSqrt.hh"

TsTFSqrt::TsTFSqrt(G4double a, G4double b) : fA(a), fB(b) {;}
TsTFSqrt::~TsTFSqrt() {;}

inline G4double TsTFSqrt::operator()(G4double t) {
		return std::sqrt(fA*t+fB);
}
