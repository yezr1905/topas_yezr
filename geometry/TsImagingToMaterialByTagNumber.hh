#ifndef TsImagingToMaterialByTagNumber_hh
#define TsImagingToMaterialByTagNumber_hh

#include "TsVImagingToMaterial.hh"

#include <map>

class TsImagingToMaterialByTagNumber : public TsVImagingToMaterial
{
public:
	TsImagingToMaterialByTagNumber(TsParameterManager* pM, TsVGeometryComponent* component,
							std::vector<G4Material*>* materialList, G4String converterNameLower);
	~TsImagingToMaterialByTagNumber();
	
	void PreloadAllMaterials();

	unsigned short AssignMaterial(std::vector< signed short >* imagingValues, G4int timeSliceIndex);

private:
	G4String GetDataType();
	std::map<G4int, unsigned short>* fMapTagNumberToMaterialListIndex;
};

#endif
