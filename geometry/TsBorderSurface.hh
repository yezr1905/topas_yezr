#ifndef TsBorderSurface_hh
#define TsBorderSurface_hh

#include "globals.hh"

class TsParameterManager;
class TsGeometryManager;

class G4LogicalBorderSurface;

class TsBorderSurface
{
  public:
	TsBorderSurface(TsParameterManager* pm, TsGeometryManager* gm,
					G4String borderSurfaceParameterName);
	virtual ~TsBorderSurface();

	void CreateBorderSurface();
	void MarkForRebuild();
	void MarkForRebuildIfMatchesDestination(G4String toComponentName);

private:
	TsParameterManager* fPm;
	TsGeometryManager* fGm;
	G4String fBorderSurfaceParameterName;
	G4String fFromComponentName;
	G4String fToComponentName;
	G4LogicalBorderSurface* fBorderSurface;
	G4bool fMarkedForRebuild;
};

#endif
