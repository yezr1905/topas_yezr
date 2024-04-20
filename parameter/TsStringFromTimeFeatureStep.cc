#include "TsTempParameter.hh"
#include "TsParameterFile.hh"
#include "TsStringFromTimeFeatureStep.hh"

TsStringFromTimeFeatureStep::TsStringFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										const G4String& nameOfBaseParameter, G4int nValues, G4String* values)
	:TsVParameter(pM, pf, tempParameter), fNameOfBaseParameter(nameOfBaseParameter), fLatestUpdatedTime(-1)
{
	QuitIfMustBeAbsolute();

	fValues                 = new G4String [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToStringVector(nValues, values, fValues, fValuesIfParameterNames);
	G4String initvalue  = tempParameter->GetValue();
	fCurrentValue = initvalue;
	fRange    = 0;
	fTimes    = new std::map<G4double, G4int>;
}


TsStringFromTimeFeatureStep::~TsStringFromTimeFeatureStep()
{
}


G4String TsStringFromTimeFeatureStep::GetType()
{
	G4String type = "s";
	return type;
}

G4String TsStringFromTimeFeatureStep::GetStringValue()
{
	fUsed = true;
	G4double t = fPm->GetCurrentSequenceTime();
	while(t >= fRange ) { t -= fRange; }
	if (t == fLatestUpdatedTime) { return fCurrentValue;}
	std::map<G4double, G4int>::const_iterator pos = fTimes->upper_bound(t);
	G4int idx = pos->second;
	if ( fValuesIfParameterNames[idx] =="") {
		return fValues[idx];
	} else {
		return EvaluateStringParameter(fValuesIfParameterNames[idx]);
	}
}

G4String TsStringFromTimeFeatureStep::GetHTMLValue() {
	G4String output  = G4UIcommand::ConvertToString( GetStringValue() );
	output += " ";
	return output;
}

void TsStringFromTimeFeatureStep::InitializeTimeFeatureValue() {
	G4int ntimes   = fPm->GetVectorLength(fNameOfBaseParameter+"/Times" );
	G4int nbvalues = fPm->GetVectorLength(fNameOfBaseParameter+"/Values");
	if (ntimes != nbvalues ) {
		G4cout<<"ERROR: # of Values must be same # of Times :"<< GetName() <<G4endl;
		fPm->AbortSession(1);
	}

	G4double* times = fPm->GetDoubleVector(fNameOfBaseParameter+"/Times", "Time");
	fRange = times[ntimes-1];
	for (int i=0; i < ntimes; ++i) {
		fTimes->insert(std::make_pair(times[i],i));
	}
}

G4bool TsStringFromTimeFeatureStep::ValueHasChanged() {
	G4String previousValue = fCurrentValue;
	G4String newValue      = GetStringValue();
	if ( newValue != previousValue) {
		fCurrentValue = newValue;
		fLatestUpdatedTime = fPm->GetCurrentSequenceTime();
		return true;
	} else {
		return false;
	}
}
