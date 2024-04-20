#include "TsTempParameter.hh"
#include "TsParameterFile.hh"
#include "TsIntegerFromTimeFeatureStep.hh"

TsIntegerFromTimeFeatureStep::TsIntegerFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										const G4String& nameOfBaseParameter, G4int nValues, G4String* values)
	:TsVParameter(pM, pf, tempParameter), fNameOfBaseParameter(nameOfBaseParameter), fLatestUpdatedTime(-1)
{
	QuitIfMustBeAbsolute();

	fValues                 = new G4int [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToIntegerVector(nValues, values, fValues, fValuesIfParameterNames);
	G4String initvalue  = tempParameter->GetValue();
	fCurrentValue = (G4UIcommand::ConvertToInt(initvalue));
	fRange    = 0;
	fTimes    = new std::map<G4double, G4int>;
}


TsIntegerFromTimeFeatureStep::~TsIntegerFromTimeFeatureStep()
{
}


G4String TsIntegerFromTimeFeatureStep::GetType()
{
	G4String type = "i";
	return type;
}

G4int TsIntegerFromTimeFeatureStep::GetIntegerValue()
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
		return EvaluateIntegerParameter(fValuesIfParameterNames[idx]);
	}
}

G4String TsIntegerFromTimeFeatureStep::GetHTMLValue() {
	G4String output  = G4UIcommand::ConvertToString( GetIntegerValue() );
	output += " ";
	return output;
}

void TsIntegerFromTimeFeatureStep::InitializeTimeFeatureValue() {
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

G4bool TsIntegerFromTimeFeatureStep::ValueHasChanged() {
	G4int previousValue = fCurrentValue;
	G4int newValue      = GetIntegerValue();
	if ( newValue != previousValue) {
		fCurrentValue = newValue;
		fLatestUpdatedTime = fPm->GetCurrentSequenceTime();
		return true;
	} else {
		return false;
	}
}
