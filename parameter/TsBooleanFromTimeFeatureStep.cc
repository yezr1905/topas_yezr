#include "TsTempParameter.hh"
#include "TsParameterFile.hh"
#include "TsBooleanFromTimeFeatureStep.hh"

TsBooleanFromTimeFeatureStep::TsBooleanFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										const G4String& nameOfBaseParameter, G4int nValues, G4String* values)
	:TsVParameter(pM, pf, tempParameter), fNameOfBaseParameter(nameOfBaseParameter), fLatestUpdatedTime(-1)
{
	QuitIfMustBeAbsolute();

	fValues                 = new G4bool [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToBooleanVector(nValues, values, fValues, fValuesIfParameterNames);
	G4String initvalue  = tempParameter->GetValue();
	if (initvalue == "\"true\"") {
		fCurrentValue = true;
	} else {
		fCurrentValue = false;
	}
	fRange    = 0;
	fTimes    = new std::map<G4double, G4int>;
}


TsBooleanFromTimeFeatureStep::~TsBooleanFromTimeFeatureStep()
{
}


G4String TsBooleanFromTimeFeatureStep::GetType()
{
	G4String type = "b";
	return type;
}

G4bool TsBooleanFromTimeFeatureStep::GetBooleanValue()
{
	fUsed = true;
	G4double t = fPm->GetCurrentSequenceTime();
	while(t >= fRange ) { t -= fRange; }
	if (t == fLatestUpdatedTime) { return fCurrentValue;}
	std::map<G4double, G4int>::const_iterator pos = fTimes->upper_bound(t);
	G4int idx = pos->second;
	if ( fValuesIfParameterNames[idx] == "" ) {
		return fValues[idx];
	} else {
		return EvaluateBooleanParameter(fValuesIfParameterNames[idx]);
	}
}

G4String TsBooleanFromTimeFeatureStep::GetHTMLValue() {
	G4String html_str;
	if ( GetBooleanValue() ) {
		html_str = "\"true\"";
	} else {
		html_str = "\"false\"";
	}
	G4String output  = G4UIcommand::ConvertToString( html_str );
	output += " ";
	return output;
}

void TsBooleanFromTimeFeatureStep::InitializeTimeFeatureValue() {
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

G4bool TsBooleanFromTimeFeatureStep::ValueHasChanged() {
	G4bool previousValue = fCurrentValue;
	G4bool newValue      = GetBooleanValue();
	if ( newValue != previousValue) {
		fCurrentValue = newValue;
		fLatestUpdatedTime = fPm->GetCurrentSequenceTime();
		return true;
	} else {
		return false;
	}
}
