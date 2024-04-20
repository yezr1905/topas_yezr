#include "TsJaws.hh"

#include "TsParameterManager.hh"

#include "G4Box.hh"
#include "G4Trap.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"

TsJaws::TsJaws(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
			 TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name) :
TsVGeometryComponent(pM, mM, gM, parentComponent, parentVolume, name)
{}


TsJaws::~TsJaws()
{}


G4VPhysicalVolume* TsJaws::Construct()
{
	BeginConstruction();

	// Half size of Jaw with respect to IEC Coordinate system (IECg).
	G4double totalLX = fPm->GetDoubleParameter(GetFullParmName("LX"), "Length");
	G4double totalLY = fPm->GetDoubleParameter(GetFullParmName("LZ"), "Length");
	G4double totalLZ = fPm->GetDoubleParameter(GetFullParmName("LY"), "Length");

	G4double totalHLX = totalLX * 0.5;
	G4double totalHLY = totalLY * 0.5;
	G4double totalHLZ = totalLZ * 0.5;

	// Positive Jaw field size at the isocenter. Need to be positive.
	G4double posFieldSize = fPm->GetDoubleParameter(GetFullParmName("PositiveFieldSetting"), "Length");

	// Negative Jaw filed size at the isocenter. Need to be negative.
	G4double negFieldSize = -1. * fPm->GetDoubleParameter(GetFullParmName("NegativeFieldSetting"), "Length");

	G4double sourceToUpstreamSurfaceDistance = fPm->GetDoubleParameter(GetFullParmName("SourceToUpstreamSurfaceDistance"), "Length");

	// Distance from Source to isocenter.
	G4double SAD = fPm->GetDoubleParameter(GetFullParmName("SAD"), "Length");

	G4double relativeLocation = sourceToUpstreamSurfaceDistance + totalHLY;
	G4double jawUpstreamLocation = relativeLocation - totalHLY;

	G4double posJawTravel = 1. / SAD * posFieldSize * jawUpstreamLocation;
	G4double posTrapezoidSize = 1. / SAD * posFieldSize * (totalHLY * 2.);

	G4double negJawTravel = 1. / SAD * negFieldSize * jawUpstreamLocation;
	G4double negTrapezoidSize = 1. / SAD * negFieldSize * (totalHLY * 2.);

	G4RotationMatrix* posJawRot = new G4RotationMatrix;
	G4RotationMatrix* negJawRot = new G4RotationMatrix;

	G4double posJawCenterOfMassCorrectionFactor = totalHLX - ((totalHLX * 2.) * (totalHLX * 2.) + ((totalHLX * 2.) - posTrapezoidSize) * ((totalHLX * 2.) - posTrapezoidSize) + ((totalHLX * 2.) - posTrapezoidSize) * (totalHLX * 2.)) / (3. * (2. * (totalHLX * 2.)  - posTrapezoidSize));
	G4double negJawCenterOfMassCorrectionFactor = totalHLX - ((totalHLX * 2.) * (totalHLX * 2.) + ((totalHLX * 2.) - negTrapezoidSize) * ((totalHLX * 2.) - negTrapezoidSize) + ((totalHLX * 2.) - negTrapezoidSize) * (totalHLX * 2.)) / (3. * (2. * (totalHLX * 2.)  - negTrapezoidSize));

	posJawRot->rotateX(270. * deg);
	posJawRot->rotateY(180. * deg);
	posJawRot->rotateZ(0. * deg);

	negJawRot->rotateX(90. * deg);
	negJawRot->rotateY(0. * deg);
	negJawRot->rotateZ(0. * deg);

	G4Box* Envelope_Jaw = new G4Box(fName, totalHLX * 4., totalHLZ, totalHLY);

	G4String posJawName = fName + "_positivejaw";
	G4String negJawName = fName + "_negativejaw";

	G4String envelopeMaterialName = fParentComponent->GetResolvedMaterialName();
	fEnvelopeLog = CreateLogicalVolume(fName, envelopeMaterialName, Envelope_Jaw);
	fEnvelopePhys = CreatePhysicalVolume(fEnvelopeLog);

	G4Trap* posJawSolid = new G4Trap(posJawName, totalHLZ * 2., totalHLY * 2., totalHLX * 2. - posTrapezoidSize, totalHLX * 2.);
	G4Trap* negJawSolid = new G4Trap(negJawName, totalHLZ * 2., totalHLY * 2., totalHLX * 2., totalHLX * 2. - negTrapezoidSize);

	G4LogicalVolume* posJawLog = CreateLogicalVolume(posJawSolid);
	G4LogicalVolume* negJawLog = CreateLogicalVolume(negJawSolid);

	CreatePhysicalVolume(posJawName, posJawLog, posJawRot,
						 new G4ThreeVector((totalHLX + posJawCenterOfMassCorrectionFactor + posJawTravel) * mm, 0. * cm, 0. * cm),
						 fEnvelopePhys);
	CreatePhysicalVolume(negJawName, negJawLog, negJawRot,
						 new G4ThreeVector((- totalHLX - negJawCenterOfMassCorrectionFactor - negJawTravel) * mm, 0. * cm, 0. * cm),
						 fEnvelopePhys);

	return fEnvelopePhys;
}
