#include "TsBorderSurface.hh"

#include "TsParameterManager.hh"
#include "TsGeometryManager.hh"

#include "TsVGeometryComponent.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4OpticalSurface.hh"

TsBorderSurface::TsBorderSurface(TsParameterManager* pm, TsGeometryManager* gm,
								 G4String borderSurfaceParameterName)
:fPm(pm), fGm(gm), fBorderSurfaceParameterName(borderSurfaceParameterName),
fBorderSurface(0), fMarkedForRebuild("true")
{
#if GEANT4_VERSION_MAJOR >= 11
	G4StrUtil::to_lower(fBorderSurfaceParameterName);
#else
	fBorderSurfaceParameterName.toLower();
#endif

	size_t pos = fBorderSurfaceParameterName.find("opticalbehaviorto");
	fFromComponentName = fBorderSurfaceParameterName.substr(3,pos-4);
	fToComponentName   = fBorderSurfaceParameterName.substr(pos+18);
}


TsBorderSurface::~TsBorderSurface()
{;}


void TsBorderSurface::CreateBorderSurface()
{
	if (fMarkedForRebuild) {
		if (fBorderSurface)
			delete fBorderSurface;

		fBorderSurface = new G4LogicalBorderSurface(fFromComponentName+"To"+fToComponentName,
						fGm->GetComponent(fFromComponentName)->GetEnvelopePhysicalVolume(),
						fGm->GetComponent(fToComponentName)->GetEnvelopePhysicalVolume(),
						fGm->GetOpticalSurface(fPm->GetStringParameter(fBorderSurfaceParameterName)));

		fMarkedForRebuild = false;
	}
}


void TsBorderSurface::MarkForRebuild()
{
	fMarkedForRebuild = true;
}


void TsBorderSurface::MarkForRebuildIfMatchesDestination(G4String toComponentName) {
#if GEANT4_VERSION_MAJOR >= 11
	G4StrUtil::to_lower(toComponentName);
#else
	toComponentName.toLower();
#endif

	if (toComponentName == fToComponentName)
		fMarkedForRebuild = true;
}
