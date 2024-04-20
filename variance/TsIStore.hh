#ifndef TsIStore_hh
#define TsIStore_hh TsIStore_hh

#include "G4GeometryCellImportance.hh"
#include "G4GeometryCellComp.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VIStore.hh"

#include <map>

class TsIStore : public G4VIStore
{
public:
	static TsIStore* GetInstance(const G4String& ParallelWorldName);

protected:
	explicit TsIStore(const G4String& ParallelWorldName);
	~TsIStore() override = default;

public:
	void AddPropertyValueToGeometryCell(G4int propertyValue, const G4GeometryCell &gCell, G4int propertyOption);
	G4int GetPropertyValue(const G4GeometryCell &gCell, G4int propertyOption);

private:
	std::map<G4GeometryCell, G4int, G4GeometryCellComp> fGeomCellNumberOfSplit;
	std::map<G4GeometryCell, G4int, G4GeometryCellComp> fGeomCellSymmetry;
	std::map<G4GeometryCell, G4int, G4GeometryCellComp> fGeomCellRussianRoulette;

	const G4VPhysicalVolume* fWorldVolume;

	static G4ThreadLocal TsIStore* fInstance;

	G4GeometryCellImportance fGeometryCelli;

public:
	G4double GetImportance(const G4GeometryCell &gCell) const override;
	G4bool IsKnown(const G4GeometryCell &gCell) const override;
	const G4VPhysicalVolume& GetWorldVolume() const override;
	virtual G4bool IsInWorld(const G4VPhysicalVolume &) const;
	virtual const G4VPhysicalVolume* GetParallelWorldVolumePointer() const;

};

#endif
