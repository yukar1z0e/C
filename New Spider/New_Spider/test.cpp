#include "dso.h"

int main(int argc, char *argv[]) {
	//module demo
	DSO_Manager dsoMgr;
	dsoMgr.load("testmodule.so", "testmodule");
	Module *testmod = dsoMgr.getModule("testmodule");
	char* buf = "test";
	testmod->(handle(void *)buf);
	return 0;
}