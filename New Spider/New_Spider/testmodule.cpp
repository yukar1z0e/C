#include "dso.h"
#include <stdio.h>

int handle(void *data) {
	printf("%s", (char *)data);
	return MODULE_OK;
}

extern int init(Module *module) {
	module = &mod;
	return MODULE_OK;
}

Module mod{
		MODULE_MAHOR_VERSION,
		MODULE_SUB_VERSION,
		__FILE__,
		init,
		handle
};