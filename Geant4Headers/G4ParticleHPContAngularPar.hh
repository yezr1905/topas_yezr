//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
//
// 080718 Add ClearHistories method and related class member
//
// P. Arce, June-2014 Conversion neutron_hp to particle_hp
// V. Ivanchenko, July-2023 Basic revision of particle HP classes
//
#ifndef G4ParticleHPContAngularPar_h
#define G4ParticleHPContAngularPar_h 1

#include "G4Cache.hh"
#include "G4InterpolationManager.hh"
#include "G4ParticleHPInterpolator.hh"
#include "G4ParticleHPList.hh"
#include "G4ReactionProduct.hh"
#include "G4ios.hh"
#include "globals.hh"

#include <fstream>
#include <set>

class G4ParticleDefinition;

class G4ParticleHPContAngularPar
{
    struct toBeCached
    {
      G4bool fresh{true};
      G4double currentMeanEnergy{-2.0};
      G4double remaining_energy{0.0};
      G4double theTargetCode{-1.0};
      G4ReactionProduct* theTarget{nullptr};
      G4ReactionProduct* thePrimary{nullptr};
      toBeCached() = default;
    };

  public:
    G4ParticleHPContAngularPar(const G4ParticleDefinition* p = nullptr);
    G4ParticleHPContAngularPar(G4ParticleHPContAngularPar&);

    ~G4ParticleHPContAngularPar();

    void Init(std::istream& aDataFile, const G4ParticleDefinition* projectile);

    G4ReactionProduct* Sample(G4double anEnergy, G4double massCode,
                              G4double mass, G4int angularRep, G4int interpol);

    G4double GetEnergy() const { return theEnergy; }

    void SetPrimary(G4ReactionProduct* aPrimary) { fCache.Get().thePrimary = aPrimary; }

    void SetTarget(G4ReactionProduct* aTarget) { fCache.Get().theTarget = aTarget; }

    void SetTargetCode(G4double aTargetCode) { fCache.Get().theTargetCode = aTargetCode; }

    void SetInterpolation(G4int theInterpolation)
    {
      theManager.Init(theInterpolation, nEnergies);  // one range only
    }

    void BuildByInterpolation(G4double anEnergy, G4InterpolationScheme aScheme,
                              G4ParticleHPContAngularPar& store1,
                              G4ParticleHPContAngularPar& store2);
    // NOTE: this interpolates legendre coefficients

    void PrepareTableInterpolation();

    G4double MeanEnergyOfThisInteraction()
    {
      G4double result = (std::max)(fCache.Get().currentMeanEnergy, 0.0);
      fCache.Get().currentMeanEnergy = -2.0;
      return result;
    }

    G4int GetNEnergies() const { return nEnergies; }
    G4int GetNDiscreteEnergies() const { return nDiscreteEnergies; }
    std::set<G4double> GetEnergiesTransformed() const { return theEnergiesTransformed; }
    G4int GetNEnergiesTransformed() const { return (G4int)theEnergiesTransformed.size(); }
    G4double GetMinEner() const { return theMinEner; }
    G4double GetMaxEner() const { return theMaxEner; }
    std::map<G4double, G4int> GetDiscreteEnergiesOwn() const { return theDiscreteEnergiesOwn; }
    G4ParticleHPList* GetAngDataList() const { return theAngular; }

    void ClearHistories()
    {
      fCache.Get().fresh = true;
      fCache.Get().currentMeanEnergy = -2.0;
      fCache.Get().remaining_energy = 0.0;
      fCache.Get().theTargetCode = -1.0;
      fCache.Get().theTarget = nullptr;
      fCache.Get().thePrimary = nullptr;
    }

    void Dump() const;

    G4ParticleHPContAngularPar& operator=(const G4ParticleHPContAngularPar &right) = delete;

  private:
    // incoming particle
    G4double theEnergy{0.0};
    G4double theMinEner{DBL_MAX};
    G4double theMaxEner{-DBL_MAX};
    // number of exit channel energies
    G4int nEnergies{0};
    // number of discrete exit channels
    G4int nDiscreteEnergies{0};
    // number of angular paramerers per channel
    G4int nAngularParameters{0};

    const G4ParticleDefinition* theProjectile{nullptr};
    // on per exit-channel energy
    G4ParticleHPList* theAngular{nullptr};

    // knows the interpolation between List labels
    G4InterpolationManager theManager;

    G4ParticleHPInterpolator theInt;

    G4Cache<toBeCached> fCache;

    G4bool adjustResult{true};
    // if not set it will not force the conservation of energy in angularRep==1,
    // but will sample the particle energy according to the database

    std::set<G4double> theEnergiesTransformed;
    std::set<G4double> theDiscreteEnergies;
    std::map<G4double, G4int> theDiscreteEnergiesOwn;
};

#endif
