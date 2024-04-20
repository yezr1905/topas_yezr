#ifndef TsNtupleBinary_hh
#define TsNtupleBinary_hh

#include "TsVNtuple.hh"

class TsNtupleBinary : public TsVNtuple
{
public:
	TsNtupleBinary(TsParameterManager* pM, G4String fileName, G4String mode, TsVFile *masterFile);
	~TsNtupleBinary();

	void RegisterColumnS(G4String* address, const G4String& name);

protected:
	void WriteBuffer();
	void GenerateColumnDescription();
};

#endif
