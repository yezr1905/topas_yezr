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
//! \file G4GeomConfig.hh
//! \brief Public preprocessor definitions for geometry

#ifndef G4GEOMCONFIG_HH
#define G4GEOMCONFIG_HH

//! \def G4GEOM_USE_USOLIDS
//! \brief Defined if all Geant4 solids use VecGeom implementations
/* #undef G4GEOM_USE_USOLIDS */

//! \def G4GEOM_USE_PARTIAL_USOLIDS
//! \brief Defined if selected Geant4 solids use VecGeom implementations
/* #undef G4GEOM_USE_PARTIAL_USOLIDS */

#ifdef G4GEOM_USE_PARTIAL_USOLIDS
//! \def G4GEOM_USE_UBOX
//! \brief Defined if G4Box is replaced with VecGeom UnplacedBox
/* #undef G4GEOM_USE_UBOX */

//! \def G4GEOM_USE_UCONS
//! \brief Defined if G4Cons is replaced with VecGeom GenericUnplacedCone
/* #undef G4GEOM_USE_UCONS */

//! \def G4GEOM_USE_UCTUBS
//! \brief Defined if G4CutTubs is replaced with VecGeom UnplacedCutTube
/* #undef G4GEOM_USE_UCTUBS */

//! \def G4GEOM_USE_UEXTRUDEDSOLID
//! \brief Defined if G4ExtrudedSolid is replaced with VecGeom UnplacedExtruded
/* #undef G4GEOM_USE_UEXTRUDEDSOLID */

//! \def G4GEOM_USE_UHYPE
//! \brief Defined if G4Hype is replaced with VecGeom GenericUnplacedHype
/* #undef G4GEOM_USE_UHYPE */

//! \def G4GEOM_USE_UGENERICPOLYCONE
//! \brief Defined if G4GenericPolycone is replaced with VecGeom UnplacedGenericPolycone
/* #undef G4GEOM_USE_UGENERICPOLYCONE */

//! \def G4GEOM_USE_UGENERICTRAP
//! \brief Defined if G4GenericTrap is replaced with VecGeom UnplacedGenTrap
/* #undef G4GEOM_USE_UGENERICTRAP */

//! \def G4GEOM_USE_UORB
//! \brief Defined if G4Orb is replaced with VecGeom UnplacedOrb
/* #undef G4GEOM_USE_UORB */

//! \def G4GEOM_USE_UPARA
//! \brief Defined if G4Para is replaced with VecGeom UnplacedParallelepiped
/* #undef G4GEOM_USE_UPARA */

//! \def G4GEOM_USE_UPARABOLOID
//! \brief Defined if G4Paraboloid is replaced with VecGeom UnplacedParaboloid
/* #undef G4GEOM_USE_UPARABOLOID */

//! \def G4GEOM_USE_UPOLYCONE
//! \brief Defined if G4Polycone is replaced with VecGeom GenericUnplacedPolycone
/* #undef G4GEOM_USE_UPOLYCONE */

//! \def G4GEOM_USE_UPOLYHEDRA
//! \brief Defined if G4Polyhedra is replaced with VecGeom UnplacedPolyhedron
/* #undef G4GEOM_USE_UPOLYHEDRA */

//! \def G4GEOM_USE_USPHERE
//! \brief Defined if G4Box is replaced with VecGeom UnplacedSphere
/* #undef G4GEOM_USE_USPHERE */

//! \def G4GEOM_USE_UTESSELLATEDSOLID
//! \brief Defined if G4TessellatedSolid is replaced with VecGeom UnplacedTessellated
/* #undef G4GEOM_USE_UTESSELLATEDSOLID */

//! \def G4GEOM_USE_UTET
//! \brief Defined if G4Tet is replaced with VecGeom UnplacedTet
/* #undef G4GEOM_USE_UTET */

//! \def G4GEOM_USE_UTRAP
//! \brief Defined if G4Trap is replaced with VecGeom UnplacedTrapezoid
/* #undef G4GEOM_USE_UTRAP */

//! \def G4GEOM_USE_UTRD
//! \brief Defined if G4Trd is replaced with VecGeom GenericUnplacedTrd
/* #undef G4GEOM_USE_UTRD */

//! \def G4GEOM_USE_UTORUS
//! \brief Defined if G4Torus is replaced with VecGeom UnplacedTorus2
/* #undef G4GEOM_USE_UTORUS */

//! \def G4GEOM_USE_UTUBS
//! \brief Defined if G4Tubs is replaced with VecGeom GenericUnplacedTube
/* #undef G4GEOM_USE_UTUBS */

#endif // G4GEOM_USE_PARTIAL_USOLIDS

#endif // G4GEOMCONFIG_HH

