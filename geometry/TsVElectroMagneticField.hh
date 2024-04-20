#ifndef TsVElectroMagneticField_hh
#define TsVElectroMagneticField_hh

#include "G4ElectricField.hh"
#include "G4RotationMatrix.hh"

class TsParameterManager;
class TsGeometryManager;
class TsVGeometryComponent;

class G4EqMagElectricField;
class G4FieldManager;
class G4MagErrorStepper;
class G4MagInt_Driver;
class G4ChordFinder;
class G4Navigator;

class TsVElectroMagneticField : public G4ElectricField{
public:
	TsVElectroMagneticField(TsParameterManager* pM, TsGeometryManager* gM,
					 TsVGeometryComponent* component);
	~TsVElectroMagneticField();

	virtual void GetFieldValue(const G4double[4], G4double *fieldBandE) const = 0;
	virtual void ResolveParameters();

	virtual void UpdateForSpecificParameterChange(G4String parameter);
	virtual void UpdateForNewRun();

	TsVGeometryComponent* GetComponent();

protected:
	TsParameterManager*	fPm;
	TsGeometryManager* fGm;

	TsVGeometryComponent* fComponent;

	G4Navigator* fNavigator;

	G4ThreeVector fElectricFieldValue;
	G4ThreeVector fMagneticFieldValue;
	G4ElectricField* fField;
	G4FieldManager* fFieldManager;
	G4EqMagElectricField* fFieldEquation;
	G4MagErrorStepper* fStepper;
	G4MagInt_Driver* fIntgrDriver;
	G4ChordFinder* fChordFinder;
};

#endif
