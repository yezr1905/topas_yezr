#ifndef TsPixelatedBox_hh
#define TsPixelatedBox_hh

#include "TsVGeometryComponent.hh"

class TsPixelatedBox : public TsVGeometryComponent
{    
public:
    TsPixelatedBox(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~TsPixelatedBox();
	
	G4VPhysicalVolume* Construct();
	void ResolveParameters(); 

private:
    G4double fLZ;
    G4double fLX;
    G4double fLY;
    G4double fPitchX;
    G4double fPitchY;
    G4int fnX;
    G4int fnY;
    
    G4double fSeparationX;
    G4double fSeparationY;
};
#endif
