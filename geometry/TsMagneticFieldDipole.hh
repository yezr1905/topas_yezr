#ifndef TsMagneticFieldDipole_hh
#define TsMagneticFieldDipole_hh

#include "TsVMagneticField.hh"

class TsMagneticFieldDipole : public TsVMagneticField
{
public:
	TsMagneticFieldDipole(TsParameterManager* pM, TsGeometryManager* gM,
						  TsVGeometryComponent* component);
	~TsMagneticFieldDipole();

	void GetFieldValue(const double p[3], double* Field) const;
	void ResolveParameters();
};

#endif
