#ifndef TsParallelWorld_hh
#define TsParallelWorld_hh

#include "G4VUserParallelWorld.hh"

class TsParallelWorld : public G4VUserParallelWorld
{
  public:
	TsParallelWorld(G4String parallelWorldName);
	virtual ~TsParallelWorld();

	void Construct();

	G4VPhysicalVolume* GetPhysicalVolume();

private:
	G4VPhysicalVolume* fPhysicalVolume;
};

#endif
