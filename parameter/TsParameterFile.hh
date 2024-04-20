#ifndef TsParameterFile_hh
#define TsParameterFile_hh

#include "globals.hh"

#include <vector>
#include <map>

class TsVParameter;
class TsParameterManager;
class TsTempParameter;

class TsParameterFile
{
public:
	TsParameterFile(TsParameterManager* pM, const G4String& fileSpec, const G4String& topFileSpec, TsParameterFile* transientFile);

	~TsParameterFile();

	TsTempParameter* AddTempParameter(const G4String& typeAndName, const G4String& value);
	void ProcessTempParameters(G4bool test = false);
	void ProtectAgainstControlByDifferentArms(G4String paramName, TsParameterFile* includeFile1, G4String prefix, G4String suffix);

	G4bool ParameterExists(const G4String& parameterName);

	G4int GetVectorLength(const G4String& parameterName);

	// Double values are returned in Geant4's internal units
	G4double GetDoubleParameter(const G4String& parameterName);
	G4double GetUnitlessParameter(const G4String& parameterName);
	G4int GetIntegerParameter(const G4String& parameterName);
	G4bool GetBooleanParameter(const G4String& parameterName);
	G4String GetStringParameter(const G4String& parameterName);

	G4double* GetDoubleVector(const G4String& parameterName);
	G4double* GetUnitlessVector(const G4String& parameterName);
	G4int* GetIntegerVector(const G4String& parameterName);
	G4bool* GetBooleanVector(const G4String& parameterName);
	G4String* GetStringVector(const G4String& parameterName);

	G4String GetHTMLValueOfParameter(const G4String& parameterName);

	G4String GetTypeOfParameter(const G4String& parameterName);
	G4String GetUnitOfParameter(const G4String& parameterName);
	G4bool IsChangeable(const G4String& parameterName);

	G4String GetTempTypeOfParameter(const G4String& parameterName);

	TsParameterFile* GetParentFile();

	void GetAllParameters(std::map<G4String, TsVParameter*>* parameterMap);
	void GetAllParametersBeforeLinearized(std::map<G4String, TsVParameter*>* parameterMap);
	void GetParameterNamesStartingWith(const G4String& value, std::vector<G4String>*);
	void GetParametersOperatingOn(const G4String& value, std::vector<TsVParameter*>*);
	void GetParameterNamesBracketedBy(const G4String& prefix, const G4String& suffix, std::vector<G4String>*);
	void CheckFilterParameterNamesStartingWith(const G4String& prefix, std::vector<G4String>*);
	void GetTimeFeatureParameters(std::vector<TsVParameter*>* );
	void BuildVectorOfParameterFiles(std::vector<TsParameterFile*>* parameterFiles);

	G4String GetFileName();

private:
	TsVParameter* ConvertTempToRealParameter(G4String, TsTempParameter*) = delete; // delete not implemented
	void CheckChainsForConflicts();

	TsVParameter* GetParameter(const G4String& parameterName);
	TsVParameter* GetParameterBeforeLinearized(const G4String& parameterName);

	void ResetParentFileTo(TsParameterFile* parent);

	void Quit(TsTempParameter* tempParameter, const char* message);
	void Quit(const G4String& parameterName, const char* message);
	void Undefined(const G4String& parameterName);

	TsParameterManager* fPm;
	G4String fFileSpec;
	G4String fDefaultFileSpec;
	G4String fIncludeFileSpecs;
	TsParameterFile* fParentFile;
	TsParameterFile* fTransientFile;

	std::vector<TsParameterFile*>* fIncludeFiles;
	std::map<G4String,TsTempParameter*>* fTempParameters;
	std::map<G4String,TsVParameter*>* fRealParameters;
	std::vector<TsVParameter*>* fTimeFeatureParameters;
};

#endif
