#pragma once
#include <string>;
using namespace std;

typedef struct _treeElem
{
	string name;
	float quantity;
	_treeElem* parent;
	_treeElem* first;
	_treeElem* second;
} Tree, *PTree;