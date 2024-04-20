#ifndef TsNtupleAscii_hh
#define TsNtupleAscii_hh

#include "TsVNtuple.hh"

class TsNtupleAscii : public TsVNtuple
{
public:
	TsNtupleAscii(TsParameterManager* pM, G4String fileName, G4String mode, TsVFile *masterFile);
	~TsNtupleAscii();

protected:
	void WriteBuffer();
	void GenerateColumnDescription();
};

#endif
