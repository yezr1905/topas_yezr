#ifndef TsVParameter_hh
#define TsVParameter_hh

#include "TsParameterManager.hh"

#include "G4UIcommand.hh"

class TsTempParameter;

class TsVParameter
{
public:
	TsVParameter(TsParameterManager* pM, TsParameterFile* pf, TsTempParameter* tempParameter);

	~TsVParameter();

	virtual void CheckRelativeParameterConsistency();
	virtual void InitializeTimeFeatureValue();

	G4bool IsChangeable();
	virtual G4bool ValueHasChanged();

	G4String GetName() {return fName;};
	virtual G4String GetType() = 0;
	virtual G4String GetUnit();

	virtual G4int GetVectorLength();

	virtual G4double GetDoubleValue();
	virtual G4double GetUnitlessValue();
	virtual G4int GetIntegerValue();
	virtual G4bool GetBooleanValue();
	virtual G4String GetStringValue();
	virtual G4double* GetDoubleVector();
	virtual G4double* GetUnitlessVector();
	virtual G4int* GetIntegerVector();
	virtual G4bool* GetBooleanVector();
	virtual G4String* GetStringVector();

	virtual G4String GetHTMLValue() = 0;

	G4bool IsUsed();

	TsParameterFile* GetParameterFile();

protected:
	void QuitIfMustBeAbsolute();

	G4double ConvertToDouble(const G4String& value);
	G4int ConvertToInteger(const G4String& value);
	G4bool ConvertToBoolean(const G4String& value);
	void ConvertToDoubleVector(G4int nValues, G4String* values, G4double* fValues, G4String* fValuesIfParameterNames);
	void ConvertToIntegerVector(G4int nValues, G4String* values, G4int* fValues, G4String* fValuesIfParameterNames);
	void ConvertToBooleanVector(G4int nValues, G4String* values, G4bool* fValues, G4String* fValuesIfParameterNames);
	void ConvertToStringVector(G4int nValues, G4String* values, G4String* fValues, G4String* fValuesIfParameterNames);
	G4int SafeConvertToInteger(const char* value);

	G4String ParseNameOfOtherParameter(const G4String& nameOfOtherParameter, const char* type);
	G4int GetLengthOfOtherParameter(const G4String& otherParameterName);

	void CheckUnit(const G4String& unit);
	void CheckUnitAgreement(const G4String& nameOfOtherParameter);
	void CheckVectorLengthAgreement(const G4String& nameOfOtherParameter);

	G4double EvaluateDoubleParameter(const G4String& nameOfOtherParameter);
	G4double EvaluateUnitlessParameter(const G4String& nameOfOtherParameter);
	G4int EvaluateIntegerParameter(const G4String& nameOfOtherParameter);
	G4bool EvaluateBooleanParameter(const G4String& nameOfOtherParameter);
	G4String EvaluateStringParameter(const G4String& nameOfOtherParameter);
	G4double* EvaluateDoubleVector(const G4String& nameOfOtherParameter);
	G4double* EvaluateUnitlessVector(const G4String& nameOfOtherParameter);
	G4int* EvaluateIntegerVector(const G4String& nameOfOtherParameter);
	G4bool* EvaluateBooleanVector(const G4String& nameOfOtherParameter);
	G4String* EvaluateStringVector(const G4String& nameOfOtherParameter);

	G4String EvaluateAsHTML(const G4String& nameOfOtherParameter);

	void OtherParameterMissing(const char* nameOfOtherParameter);
	void WrongType(const char* type);
	void WrongUnitCategory();
	void MissingUnit();
	void UnrecognizedUnit(const G4String& unit);
	void VectorCountTooLow();
	void WrongSyntax();

	TsParameterManager* fPm;

	G4bool fUsed;

private:
	TsParameterFile* fPf;
	TsTempParameter* fTempParameter;
	G4String fName;
	G4bool fIsChangeable;
};

#endif
