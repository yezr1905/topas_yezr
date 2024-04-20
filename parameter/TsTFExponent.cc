#include "TsTFExponent.hh"

TsTFExponent::TsTFExponent(G4double a, G4double b) : fA(a), fB(b) {;}
TsTFExponent::~TsTFExponent() {;}

inline G4double TsTFExponent::operator()(G4double t) {
	return std::exp(fA*t+fB);
}
