#include "TsForcedInteraction.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"

#include "globals.hh"
#include <vector>

TsForcedInteraction::TsForcedInteraction(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name)
{
	ResolveParameters();
}


TsForcedInteraction::~TsForcedInteraction()
{;}


void TsForcedInteraction::ResolveParameters() {
	G4String prefix = GetFullParmName("ForRegion");
	G4String subfix = "processesNamed";
	std::vector<G4String>* regionNames = new std::vector<G4String>;
	G4bool found;

	fPm->GetParameterNamesBracketedBy(prefix, subfix, regionNames);
	G4int numberOfRegions = regionNames->size();
	if ( numberOfRegions > 0 ) {
		for ( int i = 0; i < numberOfRegions; i++ ) {
			G4String aRegionName = (*regionNames)[i];
			aRegionName.toLower();
			if ( aRegionName == "defaultregionfortheworld" )
				aRegionName = "DefaultRegionForTheWorld";
			
			found = false;
			for ( int j = i + 1; j < numberOfRegions; j++ ) {
				G4String tempRegName = (*regionNames)[j];
				tempRegName.toLower();
				if ( tempRegName == "defaultregionfortheworld")
					tempRegName = "DefaultRegionForTheWorld";
				
				if ( aRegionName == tempRegName )
					found = true;
			}
			
			if (!found) {
				aRegionName = aRegionName.substr(0,aRegionName.length()-subfix.length()-1);
				aRegionName = aRegionName.substr(prefix.length()+1);
				fRegionName.push_back(aRegionName);
				
				G4String parmName = "forregion/"+aRegionName+"/";
				G4int procNameSize = fPm->GetVectorLength(GetFullParmName(parmName+"ProcessesNamed"));
				
				if ( procNameSize != fPm->GetVectorLength(GetFullParmName(parmName+"ForcedDistances")) ) {
					Quit(GetFullParmName(parmName+"ProcessesNamed"),
						 "size does not match with size of parameter named: "
						 + GetFullParmName(parmName + "ForcedDistances"));
				}
			}
		}
	}
}


void TsForcedInteraction::Initialize() {
	SetForcedInteraction();
	return;
}


void TsForcedInteraction::SetForcedInteraction() {
	for ( int i = 0; i < int(fRegionName.size()); i++ ) {
		G4String parmName = "ForRegion/"+fRegionName[i]+"/";
		G4String* procName = fPm->GetStringVector(GetFullParmName(parmName+"ProcessesNamed"));
		G4int procNameSize = fPm->GetVectorLength(GetFullParmName(parmName+"ProcessesNamed"));
		G4double* forcedDistances = fPm->GetDoubleVector(GetFullParmName(parmName+"ForcedDistances"), "Length");
		G4bool correctByWeight = false;
		if ( fPm->ParameterExists(GetFullParmName(parmName+"CorrectByWeight")))
			correctByWeight = fPm->GetBooleanParameter(GetFullParmName(parmName+"CorrectByWeight"));
		
		if ( fRegionName[i] == "defaultregionfortheworld" )
			fRegionName[i] = "DefaultRegionForTheWorld";
		
		G4String sCorrectByWeight = !correctByWeight ? " false " : " true ";
		for ( int j = 0; j < procNameSize; j++ ) {
			G4String command ="/process/em/setForcedInteraction " + procName[j] + " " + fRegionName[i] + " " +
			G4UIcommand::ConvertToString(forcedDistances[j]/mm, "mm") + sCorrectByWeight;
			G4UImanager::GetUIpointer()->ApplyCommand(command);
			G4cout << "-- Forced interaction will be corrected by weight: "  + sCorrectByWeight << G4endl;
		}
	}
}


void TsForcedInteraction::Clear() {
	return;
}
