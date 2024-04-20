#include "TsMain.hh"

int main(int argc,char** argv) {
	TsMain* tsMain = new TsMain(argc, argv);
	delete tsMain;
	return 0;
}
