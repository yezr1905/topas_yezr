#ifndef TsParameterisation_hh
#define TsParameterisation_hh

#include "G4VPVParameterisation.hh"

class TsVGeometryComponent;
class G4Box;
class G4Cons;
class G4Hype;
class G4Orb;
class G4Para;
class G4Polycone;
class G4Polyhedra;
class G4Sphere;
class G4Torus;
class G4Trap;
class G4Trd;
class G4Tubs;

class TsParameterisation : public G4VPVParameterisation, public G4VVolumeMaterialScanner {

public:
	TsParameterisation(TsVGeometryComponent* component);
	virtual ~TsParameterisation();

	virtual G4Material* ComputeMaterial(const G4int repNo, G4VPhysicalVolume* pvol, const G4VTouchable* parent);
	G4VVolumeMaterialScanner* GetMaterialScanner();
	G4int       GetNumberOfMaterials() const;
	G4Material* GetMaterial(G4int idx) const;

	virtual void ComputeTransformation(const G4int, G4VPhysicalVolume*) const;

	virtual void ComputeDimensions(G4Tubs& tubs, const G4int copyNo, const G4VPhysicalVolume*) const;
	virtual void ComputeDimensions(G4Sphere& sphere, const G4int copyNo, const G4VPhysicalVolume*) const;

	virtual G4bool IsNested() const;

private:
	TsVGeometryComponent* fComponent;

	void ComputeDimensions (G4Box&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Cons&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Hype&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Orb&,const G4int,const G4VPhysicalVolume*)  const {}
	void ComputeDimensions (G4Para&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Polycone&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Polyhedra&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Torus&,const G4int,const G4VPhysicalVolume*)const {}
	void ComputeDimensions (G4Trap&,const G4int,const G4VPhysicalVolume*) const {}
	void ComputeDimensions (G4Trd&,const G4int,const G4VPhysicalVolume*)  const {}
};

#endif
