#include "TsUniformSplitting.hh"
#include "TsGeometryManager.hh"
#include "TsParameterManager.hh"

#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include "globals.hh"
#include <vector>

TsUniformSplitting::TsUniformSplitting(G4String name, TsParameterManager* pM, TsGeometryManager* gM)
	: TsVBiasingProcess(name, pM, gM), fPm(pM), fName(name), fUseDirectionalSplitting(false),
	  fTransX(0), fTransY(0), fTransZ(0), fRMax(0)
{
}

TsUniformSplitting::~TsUniformSplitting()
{;}


void TsUniformSplitting::ResolveParameters() {
	fType = fPm->GetStringParameter(GetFullParmName("Type"));
	G4String prefix = GetFullParmName("ForRegion");
	G4String subfix = "processesNamed";
	std::vector<G4String>* regionNames = new std::vector<G4String>;
	fPm->GetParameterNamesBracketedBy(prefix, subfix, regionNames);
	G4int numberOfRegions = regionNames->size();
	G4bool found;
	if ( numberOfRegions > 0 ) {
		for ( int i = 0; i < numberOfRegions; i++ ) {
			G4String aRegionName = (*regionNames)[i];
			aRegionName.toLower();
			found = false;
			for ( int j = i + 1; j < numberOfRegions; j++ ) {
				G4String tempRegName = (*regionNames)[j];
				tempRegName.toLower();
				if ( aRegionName == tempRegName )
					found = true;
			}
			
			if (!found) {
				aRegionName = aRegionName.substr(0,aRegionName.length()-subfix.length()-1);
				aRegionName = aRegionName.substr(prefix.length()+1);
				fRegionName.push_back(aRegionName);
				
				G4String parmName = "forregion/"+aRegionName+"/";
				G4int procNameSize = fPm->GetVectorLength(GetFullParmName(parmName+"ProcessesNamed"));
				G4int splSize = fPm->GetVectorLength(GetFullParmName(parmName+"SplitNumber"));
				G4int maxEnergiesSize = fPm->GetVectorLength(GetFullParmName(parmName+"MaximumEnergies"));
				
				if ( procNameSize != splSize ) {
					Quit(GetFullParmName(parmName+"SplitNumber"),
						 "size does not match with size of parameter named: " +
						 GetFullParmName(parmName+"ProcessesNamed"));
				} else if ( procNameSize != maxEnergiesSize ) {
					Quit(GetFullParmName(parmName+"SplitNumber"),
						 "size does not match with size of parameter named: " +
						 GetFullParmName(parmName+"MaximumEnergies"));
				}
				
				G4String* procName = fPm->GetStringVector(GetFullParmName(parmName + "ProcessesNamed"));
				G4double* splitNumber = fPm->GetUnitlessVector(GetFullParmName(parmName + "SplitNumber"));
				G4double* maxEnergies = fPm->GetDoubleVector(GetFullParmName(parmName + "MaximumEnergies"), "Energy");
				for ( int j = 0; j < procNameSize; j++ ) {
					fProcesses.push_back(procName[j]);
					fSplitNumber.push_back(splitNumber[j]);
					fLowerEnergyLimitForRussianRoulette.push_back(maxEnergies[j]);
				}
			}
		}
	}
	
	if ( fPm->ParameterExists(GetFullParmName("UseDirectionalSplitting")) ) {
		fUseDirectionalSplitting = fPm->GetBooleanParameter(GetFullParmName("UseDirectionalSplitting"));
		fTransX = fPm->GetDoubleParameter(GetFullParmName("TransX"), "Length");
		fTransY = fPm->GetDoubleParameter(GetFullParmName("TransY"), "Length");
		fTransZ = fPm->GetDoubleParameter(GetFullParmName("TransZ"), "Length");
		fRMax = fPm->GetDoubleParameter(GetFullParmName("RMax"), "Length");
	}
}


void TsUniformSplitting::Initialize() {
	Clear();
	ResolveParameters();
	SetUniformSplitting();
}


void TsUniformSplitting::Clear() {
	fProcesses.clear();
	fSplitNumber.clear();
	fLowerEnergyLimitForRussianRoulette.clear();
	fRegionName.clear();
}


void TsUniformSplitting::SetUniformSplitting() {
	G4String command = "None";
	for ( int j = 0; j < (G4int)fProcesses.size(); j++ ) {
		for ( int i = 0; i < int(fRegionName.size()); i++ ) {
			command ="/process/em/setSecBiasing " + fProcesses[j] + " " + fRegionName[i] + " " +
			G4UIcommand::ConvertToString(fSplitNumber[j]) + " " +
			G4UIcommand::ConvertToString(fLowerEnergyLimitForRussianRoulette[j], "MeV");
			G4UImanager::GetUIpointer()->ApplyCommand(command);
			G4cout << " commamd " << command << G4endl;
		}
	}

	if ( fUseDirectionalSplitting ) {
		G4cout << "-Using Geant4 directional splitting" << G4endl;
		command = "/process/em/setDirectionalSplitting true";
		G4UImanager::GetUIpointer()->ApplyCommand(command);

		command = "/process/em/setDirectionalSplittingTarget " +
		G4UIcommand::ConvertToString(G4ThreeVector(fTransX, fTransY, fTransZ), "cm");
		G4UImanager::GetUIpointer()->ApplyCommand(command);
		
		command = "/process/em/setDirectionalSplittingRadius " +
		G4UIcommand::ConvertToString(fRMax, "cm");
		G4UImanager::GetUIpointer()->ApplyCommand(command);
	} else {
		command = "/process/em/setDirectionalSplitting false";
		G4UImanager::GetUIpointer()->ApplyCommand(command);
	}
}
