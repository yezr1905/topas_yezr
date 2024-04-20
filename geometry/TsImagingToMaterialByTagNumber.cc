#include "TsImagingToMaterialByTagNumber.hh"

#include "TsParameterManager.hh"

#include "G4Material.hh"

TsImagingToMaterialByTagNumber::TsImagingToMaterialByTagNumber(TsParameterManager* pM, TsVGeometryComponent* component,
												 std::vector<G4Material*>* materialList, G4String)
:TsVImagingToMaterial(pM, component, materialList) {
	// Create map from material tag number to material list index
	fMapTagNumberToMaterialListIndex = new std::map<G4int, unsigned short>;

	G4int numberOfMaterials = fPm->GetVectorLength(GetFullParmName("MaterialTagNumbers"));

	if (fPm->GetVectorLength(GetFullParmName("MaterialNames")) != numberOfMaterials) {
		G4cerr << "Topas is exiting due to a serious error." << G4endl;
		G4cerr << "The length of the vector paremeter " << GetFullParmName("MaterialTagNumbers") << G4endl;
		G4cerr << "does not match the length of the vector paremeter " << GetFullParmName("MaterialNames") << G4endl;
		fPm->AbortSession(1);
	}

	G4int* materialTagNumbers = fPm->GetIntegerVector(GetFullParmName("MaterialTagNumbers"));
	G4String* materialNames = fPm->GetStringVector(GetFullParmName("MaterialNames"));

	for (unsigned short iMaterial = 0; iMaterial < numberOfMaterials; iMaterial++) {
		//G4cout << "Evaluating material tag: " << materialTagNumbers[iMaterial] <<
		//", material name: " << materialNames[iMaterial] << G4endl;

		G4Material* materialPointer = GetMaterial(materialNames[iMaterial]);
		
		//G4cout << "Found material: " << materialPointer->GetName() << G4endl;

		// Insert the material into the materials list
		fMaterialList->push_back(materialPointer);

		// Note index into materials list for this material tag number
		fMapTagNumberToMaterialListIndex->insert(std::pair<G4int, unsigned short>(materialTagNumbers[iMaterial], iMaterial));
	}
}


TsImagingToMaterialByTagNumber::~TsImagingToMaterialByTagNumber() {
}


G4String TsImagingToMaterialByTagNumber::GetDataType() {
	return "s";
}


void TsImagingToMaterialByTagNumber::PreloadAllMaterials() {
	// Not bothering to implement since not worrying about 4DCT
}


unsigned short TsImagingToMaterialByTagNumber::AssignMaterial(std::vector< signed short >* imagingValues, G4int) {

	//G4cout << "AssignMaterial called for material tag: " << (*imagingValues)[0] << G4endl;
	std::map<G4int, unsigned short>::iterator it = fMapTagNumberToMaterialListIndex->find((*imagingValues)[0]);
	
	if(it == fMapTagNumberToMaterialListIndex->end()) {
		G4cerr << "Topas is exiting due to a serious error." << G4endl;
		G4cerr << "The ImageCube contains the material tag number: " << (*imagingValues)[0] << G4endl;
		G4cerr << "However this tag number does not appear in " << GetFullParmName("MaterialTagNumbers") << G4endl;
		fPm->AbortSession(1);
	}

	unsigned short materialListIndex = it->second;
	//G4cout << "Found materialListIndex: " << materialListIndex << G4endl;
	
	return materialListIndex;
}
