#ifndef TsVMagneticField_hh
#define TsVMagneticField_hh

#include "G4MagneticField.hh"
#include "G4RotationMatrix.hh"

class TsParameterManager;
class TsGeometryManager;
class TsVGeometryComponent;
class G4Mag_UsualEqRhs;
class G4FieldManager;
class G4MagIntegratorStepper;
class G4ChordFinder;
class G4Navigator;

class TsVMagneticField : public G4MagneticField{
public:
	TsVMagneticField(TsParameterManager* pM, TsGeometryManager* gM,
					 TsVGeometryComponent* component);
	~TsVMagneticField();

	virtual void GetFieldValue(const double Point[3], double* BField) const = 0;
	virtual void ResolveParameters();

	virtual void UpdateForSpecificParameterChange(G4String parameter);
	virtual void UpdateForNewRun();

	TsVGeometryComponent* GetComponent();

protected:
	TsParameterManager*	fPm;
	TsGeometryManager* fGm;

	TsVGeometryComponent* fComponent;

	G4Navigator* fNavigator;

	G4ThreeVector fFieldValue;
	G4FieldManager* fFieldManager;
	G4Mag_UsualEqRhs* fMagFieldEquation;
	G4MagIntegratorStepper* fStepper;
	G4ChordFinder* fChordFinder;
};

#endif
