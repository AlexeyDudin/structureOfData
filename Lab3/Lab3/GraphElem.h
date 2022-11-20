#pragma once
#include <string>
#include <vector>
using namespace std;

typedef struct _graphElement
{
	string name;
	bool isReturned;
} GraphElem, *PGraphElem;

typedef struct _path
{
	PGraphElem left, right;
	unsigned long size;
} Path, *PPath;