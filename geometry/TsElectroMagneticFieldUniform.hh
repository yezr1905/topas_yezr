#ifndef TsElectroMagneticFieldUniform_hh
#define TsElectroMagneticFieldUniform_hh

#include "TsVElectroMagneticField.hh"

class TsElectroMagneticFieldUniform : public TsVElectroMagneticField
{
public:
	TsElectroMagneticFieldUniform(TsParameterManager* pM, TsGeometryManager* gM,
						  TsVGeometryComponent* component);
	~TsElectroMagneticFieldUniform();

	void GetFieldValue(const G4double[4], G4double *fieldBandE) const;
	void ResolveParameters();
};

#endif
