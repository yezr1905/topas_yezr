#include "TsParallelWorld.hh"

TsParallelWorld::TsParallelWorld(G4String parallelWorldName)
:G4VUserParallelWorld(parallelWorldName), fPhysicalVolume(0)
{
}


TsParallelWorld::~TsParallelWorld()
{;}


void TsParallelWorld::Construct()
{
	fPhysicalVolume = GetWorld();
}


G4VPhysicalVolume* TsParallelWorld::GetPhysicalVolume()
{
	if (!fPhysicalVolume)
		Construct();
	return fPhysicalVolume;
}
