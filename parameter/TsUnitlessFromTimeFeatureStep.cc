#include "TsTempParameter.hh"
#include "TsParameterFile.hh"
#include "TsUnitlessFromTimeFeatureStep.hh"

TsUnitlessFromTimeFeatureStep::TsUnitlessFromTimeFeatureStep(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										const G4String& nameOfBaseParameter, G4int nValues, G4String* values)
	:TsVParameter(pM, pf, tempParameter), fNameOfBaseParameter(nameOfBaseParameter), fLatestUpdatedTime(-1)
{
	QuitIfMustBeAbsolute();

	fValues                 = new G4double [nValues];
	fValuesIfParameterNames = new G4String[nValues];
	ConvertToDoubleVector(nValues, values, fValues, fValuesIfParameterNames);
	G4String initvalue  = tempParameter->GetValue();
	fCurrentValue = (G4UIcommand::ConvertToDouble(initvalue));
	fRange    = 0;
	fTimes    = new std::map<G4double, G4int>;
}


TsUnitlessFromTimeFeatureStep::~TsUnitlessFromTimeFeatureStep()
{
}


G4String TsUnitlessFromTimeFeatureStep::GetType()
{
	G4String type = "u";
	return type;
}

G4double TsUnitlessFromTimeFeatureStep::GetUnitlessValue()
{
	fUsed = true;
	G4double t = fPm->GetCurrentSequenceTime();
	while(t >= fRange ) { t -= fRange; }
	if (t == fLatestUpdatedTime) { return fCurrentValue;}
	std::map<G4double, G4int>::const_iterator pos = fTimes->upper_bound(t);
	G4int idx = pos->second;
	if ( fValuesIfParameterNames[idx] =="" ) {
		return fValues[idx];
	} else {
		return EvaluateUnitlessParameter(fValuesIfParameterNames[idx]);
	}
}

G4String TsUnitlessFromTimeFeatureStep::GetHTMLValue()
{
	G4String output  = G4UIcommand::ConvertToString( GetUnitlessValue() );
	output += " ";
	return output;
}

void TsUnitlessFromTimeFeatureStep::InitializeTimeFeatureValue()
{
	G4int ntimes   = fPm->GetVectorLength(fNameOfBaseParameter+"/Times" );
	G4int nbvalues = fPm->GetVectorLength(fNameOfBaseParameter+"/Values");
	if (ntimes != nbvalues ) {
		G4cerr<<"ERROR: # of Values must be same # of Times :"<< GetName() <<G4endl;
		fPm->AbortSession(1);
	}

	G4double* times = fPm->GetDoubleVector(fNameOfBaseParameter+"/Times", "Time");
	fRange = times[ntimes-1];
	for (int i=0; i < ntimes; ++i) {
		fTimes->insert(std::make_pair(times[i],i));
	}
}

G4bool TsUnitlessFromTimeFeatureStep::ValueHasChanged() {
	G4double previousValue = fCurrentValue;
	G4double newValue      = GetUnitlessValue();
	if ( newValue != previousValue) {
		fCurrentValue = newValue;
		fLatestUpdatedTime = fPm->GetCurrentSequenceTime();
		return true;
	} else {
		return false;
	}
}
