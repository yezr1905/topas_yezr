#ifndef TsTempParameter_hh
#define TsTempParameter_hh

#include "globals.hh"

class TsTempParameter
	{
	public:
		TsTempParameter(const G4String& name, const G4String& type, const G4String& value, G4bool isChangeable):
		fName(name), fType(type), fValue(value), fIsChangeable(isChangeable), fMustBeAbsolute(false) {};

		TsTempParameter() {};

		~TsTempParameter() {};

		const G4String& GetName()const{return fName;};
		const G4String& GetType()const{return fType;};
		const G4String& GetValue()const{return fValue;};
		const G4bool& IsChangeable()const{return fIsChangeable;};
		const G4bool& MustBeAbsolute()const{return fMustBeAbsolute;};

		void SetName(const G4String& name) {fName = name;};
		void SetType(const G4String& type) {fType = type;};
		void SetChangeable(const G4bool& isChangeable) {fIsChangeable = isChangeable;};
		void SetMustBeAbsolute() {fMustBeAbsolute = true;};

	private:
		G4String fName;
		G4String fType;
		G4String fValue;
		G4bool fIsChangeable;
		G4bool fMustBeAbsolute;
	};

#endif
