#ifndef TsMagneticFieldQuadrupole_hh
#define TsMagneticFieldQuadrupole_hh

#include "TsVMagneticField.hh"

class TsMagneticFieldQuadrupole : public TsVMagneticField
{
public:
	TsMagneticFieldQuadrupole(TsParameterManager* pM, TsGeometryManager* gM,
							  TsVGeometryComponent* component);
	~TsMagneticFieldQuadrupole();

	void GetFieldValue(const double p[3], double* Field) const;
	void ResolveParameters();

private:
	G4double fGradientX;
	G4double fGradientY;
};

#endif
