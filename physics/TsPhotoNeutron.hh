#ifndef TsPhotoNeutron_h
#define TsPhotoNeutron_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class TsParameterManager;

class TsPhotoNeutron : public G4VPhysicsConstructor
{
public:
  TsPhotoNeutron(TsParameterManager* pM);
  TsPhotoNeutron(G4int ver = 0);

  virtual ~TsPhotoNeutron();

  virtual void ConstructParticle() {};
  virtual void ConstructProcess();

};
#endif

