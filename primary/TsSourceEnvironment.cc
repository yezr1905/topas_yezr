#include "TsSourceEnvironment.hh"

#include "TsVGeometryComponent.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

TsSourceEnvironment::TsSourceEnvironment(TsParameterManager* pM, TsSourceManager* psM, G4String sourceName)
: TsSource(pM, psM, sourceName)
, fAccumulatedFluence(0.)
{}

TsSourceEnvironment::~TsSourceEnvironment()
{}

void TsSourceEnvironment::UpdateForEndOfRun()
{
	G4int nHistories = GetNumberOfHistoriesInRun();
	G4double radius = fComponent->GetExtent().GetExtentRadius();
	G4double fluence = nHistories/(pi*radius*radius);  // See documentation
	fAccumulatedFluence += fluence;

	G4cout << "\nTsSourceEnvironment::UpdateForEndOfRun" << G4endl;
	G4cout << "An isotropic, homogenous particle flux was generated on the inner surface of a spherical cavity." << G4endl;
	G4cout << "Radius of cavity is " << G4BestUnit(radius,"Length") << G4endl;
	G4cout << nHistories << " histories in this run" << G4endl;
	G4cout << "Omnidirectional fluence ( /mm2 ): " << fluence*mm2 << G4endl;
	G4cout << "Accumulated fluence this session ( /mm2 ): " << fAccumulatedFluence*mm2 << G4endl;
}
