#pragma once

#ifndef DSO_H
#define DSO_H

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

#define MODULE_OK 0
#define MODULE_ERR 1

#define MODULE_MAHOR_VERSION 1
#define MODULE_SUB_VERSION 0

typedef struct Module {
	int version;
	int sub_ver;
	char *name;
	void(*init)(Module*);
	int(*handle)(void*);
}Module;

class DSO_Manager {
public:
	int load(char* path, char* name);
	int getModule(char* name);

private:
	map<string, Module* > Modules;

};
#endif //DSO_H
