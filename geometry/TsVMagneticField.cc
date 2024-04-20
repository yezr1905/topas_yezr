#include "TsVMagneticField.hh"

#include "TsParameterManager.hh"
#include "TsGeometryManager.hh"

#include "TsVGeometryComponent.hh"

#include "G4LogicalVolume.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4FieldManager.hh"
#include "G4ChordFinder.hh"
#include "G4SimpleHeum.hh"
#include "G4SimpleRunge.hh"
#include "G4HelixImplicitEuler.hh"
#include "G4HelixExplicitEuler.hh"
#include "G4HelixSimpleRunge.hh"
#include "G4CashKarpRKF45.hh"
#include "G4RKG3_Stepper.hh"
#include "G4ClassicalRK4.hh"
#include "G4ExplicitEuler.hh"
#include "G4ImplicitEuler.hh"
#include "G4SystemOfUnits.hh"
#include "G4TransportationManager.hh"

TsVMagneticField::TsVMagneticField(TsParameterManager* pM, TsGeometryManager* gM,
								   TsVGeometryComponent* component):
fPm(pM), fGm(gM), fComponent(component) {
	fGm->SetCurrentMagneticField(this);

	fNavigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();

	fMagFieldEquation = new G4Mag_UsualEqRhs( this );

	G4String stepper_name = "ClassicalRK4";
	if (fPm->ParameterExists(fComponent->GetFullParmName("FieldStepper")))
		stepper_name = fPm->GetStringParameter(fComponent->GetFullParmName("FieldStepper"));

	stepper_name.toLower();
	if (stepper_name == "expliciteuler")
		fStepper = new G4ExplicitEuler(fMagFieldEquation);
	else if (stepper_name == "impliciteuler")
		fStepper = new G4ImplicitEuler(fMagFieldEquation);
	else if (stepper_name == "simplerunge")
		fStepper = new G4SimpleRunge(fMagFieldEquation);
	else if (stepper_name == "simpleheum")
		fStepper = new G4SimpleHeum(fMagFieldEquation);
	else if (stepper_name == "helixexpliciteuler")
		fStepper = new G4HelixExplicitEuler(fMagFieldEquation);
	else if (stepper_name == "heliximpliciteuler")
		fStepper = new G4HelixImplicitEuler(fMagFieldEquation);
	else if (stepper_name == "helixsimplerunge")
		fStepper = new G4HelixSimpleRunge(fMagFieldEquation);
	else if (stepper_name == "cashkarprkf45")
		fStepper = new G4CashKarpRKF45(fMagFieldEquation);
	else if (stepper_name == "rkg3")
		fStepper = new G4RKG3_Stepper(fMagFieldEquation);
	else
		fStepper = new G4ClassicalRK4(fMagFieldEquation);

	G4double StepMin = 1.0 * mm;
	if (fPm->ParameterExists(fComponent->GetFullParmName("FieldStepMinimum")))
		StepMin = fPm->GetDoubleParameter(fComponent->GetFullParmName("FieldStepMinimum"), "Length");

	G4double dChord = 1.0e-1 * mm;;
	if (fPm->ParameterExists(fComponent->GetFullParmName("FieldDeltaChord")))
		dChord = fPm->GetDoubleParameter(fComponent->GetFullParmName("FieldDeltaChord"), "Length");

	fChordFinder = new G4ChordFinder(this, StepMin, fStepper);
	fChordFinder->SetDeltaChord(dChord);
	fFieldManager = new G4FieldManager(this, fChordFinder, false );
	fComponent->GetEnvelopeLogicalVolume()->SetFieldManager(fFieldManager ,true);
}


TsVMagneticField::~TsVMagneticField() {;}


void TsVMagneticField::ResolveParameters() {
}


void TsVMagneticField::UpdateForSpecificParameterChange(G4String parameter)
{
	if (fPm->GetIntegerParameter("Ts/SequenceVerbosity") > 0)
		G4cout << "TsVMagneticField::UpdateForSpecificParameterChange called to do nothing for parameter: " << parameter << G4endl;
}


void TsVMagneticField::UpdateForNewRun() {
	ResolveParameters();
}


TsVGeometryComponent* TsVMagneticField::GetComponent() {
	return fComponent;
}
