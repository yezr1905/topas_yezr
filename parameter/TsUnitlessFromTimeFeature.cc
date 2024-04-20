#include "TsTempParameter.hh"
#include "TsUnitlessFromTimeFeature.hh"
#include "G4Tokenizer.hh"
#include "TsTFLinear.hh"
#include "TsTFSine.hh"
#include "TsTFCosine.hh"
#include "TsTFExponent.hh"
#include "TsTFSqrt.hh"

TsUnitlessFromTimeFeature::TsUnitlessFromTimeFeature(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter,
										const G4String& nameOfBaseParameter)
	:TsVParameter(pM, pf, tempParameter), fNameOfBaseParameter(nameOfBaseParameter), fLatestUpdatedTime(-1)
{
	QuitIfMustBeAbsolute();

	G4String initvalue  = tempParameter->GetValue();
	fCurrentValue = (G4UIcommand::ConvertToDouble(initvalue));
	fRange = DBL_MAX;
}


TsUnitlessFromTimeFeature::~TsUnitlessFromTimeFeature()
{
}


G4String TsUnitlessFromTimeFeature::GetType()
{
	G4String type = "u";
	return type;
}

G4double TsUnitlessFromTimeFeature::GetUnitlessValue()
{
	fUsed = true;
	G4double t = fPm->GetCurrentSequenceTime();
	while(t >= fRange ) { t -= fRange; }
	if (t == fLatestUpdatedTime) { return fCurrentValue;}
	return ((*fFunction)(t));
}


G4String TsUnitlessFromTimeFeature::GetHTMLValue()
{
	G4String output  = G4UIcommand::ConvertToString( GetUnitlessValue() );
	output += " ";
	return output;
}

void TsUnitlessFromTimeFeature::InitializeTimeFeatureValue() {
	G4String funcValue = fPm->GetStringParameter(G4String(fNameOfBaseParameter+"/Function"));
	G4Tokenizer next(funcValue);
	G4String funcname = next(); funcname.toLower();
	G4String category1;
	G4String category2;
	G4double rate;
	G4double startvalue;

	if (fPm->ParameterExists(G4String(fNameOfBaseParameter+"/RepetitionInterval")))
		fRange    = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/RepetitionInterval"), "Time");

	if ( funcname == "linear") {
		category2="/Time";
		startvalue = fPm->GetUnitlessParameter(G4String(fNameOfBaseParameter+"/StartValue"));
		rate       = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/Rate"), category2);
		fFunction = new TsTFLinear(rate, startvalue);
	} else if (funcname == "sine") {
		category1="Angle";
		category2="Angle/Time";
		startvalue = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/StartValue"), category1);
		rate       = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/Rate"), category2);
		fFunction = new TsTFSine(rate, startvalue);
	} else if (funcname == "cosine") {
		category1="Angle";
		category2="Angle/Time";
		startvalue = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/StartValue"), category1);
		rate       = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/Rate"), category2);
		fFunction = new TsTFCosine(rate, startvalue);
	} else if (funcname == "exponent") {
		category2="/Time";
		startvalue = fPm->GetUnitlessParameter(G4String(fNameOfBaseParameter+"/StartValue"));
		rate       = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/Rate"), category2);
		fFunction = new TsTFExponent(rate, startvalue);
	} else if (funcname == "sqrt") {
		category2="/Time";
		startvalue = fPm->GetUnitlessParameter(G4String(fNameOfBaseParameter+"/StartValue"));
		rate       = fPm->GetDoubleParameter(G4String(fNameOfBaseParameter+"/Rate"), category2);
		fFunction = new TsTFSqrt(rate, startvalue);
	} else {
		G4cerr<<"[TOPAS-TimeFeature] Can't find TimeFunction for given " << funcname <<" TimeFunction"<<G4endl;
		fPm->AbortSession(1);
	}
}

G4bool TsUnitlessFromTimeFeature::ValueHasChanged() {
	G4double previousValue = fCurrentValue;
	G4double newValue = GetUnitlessValue();
	if ( newValue != previousValue) {
		fCurrentValue = newValue;
		fLatestUpdatedTime = fPm->GetCurrentSequenceTime();
		return true;
	} else {
		return false;
	}
}
