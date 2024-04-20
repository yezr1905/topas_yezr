#include "TsParameterisation.hh"

#include "TsVGeometryComponent.hh"

#include "G4VVolumeMaterialScanner.hh"

TsParameterisation::TsParameterisation(TsVGeometryComponent* component):G4VPVParameterisation(), G4VVolumeMaterialScanner(),
fComponent(component)
{}

TsParameterisation::~TsParameterisation() {}

G4Material* TsParameterisation::ComputeMaterial(const G4int repNo, G4VPhysicalVolume* pvol, const G4VTouchable* parent)
{
	return fComponent->ComputeMaterial(repNo, pvol, parent);
}


G4VVolumeMaterialScanner* TsParameterisation::GetMaterialScanner()
{
   return this;
}


G4int TsParameterisation::GetNumberOfMaterials() const
{
	return fComponent->GetNumberOfMaterials();
}


G4Material* TsParameterisation::GetMaterial(G4int i) const
{
	return fComponent->GetMaterialInVoxel(i);
}


void TsParameterisation::ComputeTransformation(const G4int copyNo, G4VPhysicalVolume* pvol) const
{
	fComponent->ComputeTransformation(copyNo, pvol);
}



void TsParameterisation::ComputeDimensions(G4Tubs& tubs, const G4int copyNo, const G4VPhysicalVolume* pvol) const
{
	fComponent->ComputeDimensions(tubs, copyNo, pvol);
}


void TsParameterisation::ComputeDimensions(G4Sphere& sphere, const G4int copyNo, const G4VPhysicalVolume* pvol) const
{
	fComponent->ComputeDimensions(sphere, copyNo, pvol);
}

G4bool TsParameterisation::IsNested() const
{
	return true;
}
