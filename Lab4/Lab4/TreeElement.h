#pragma once
#include <string>
#include "Contact.h"

typedef struct _treeElem {
	Contact contact;
	_treeElem* left;
	_treeElem* right;
};