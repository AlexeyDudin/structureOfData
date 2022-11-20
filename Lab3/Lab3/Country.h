#pragma once
#include "GraphElem.h"

typedef struct _country
{
	PGraphElem capital;
	vector<PPath> paths;
	vector<PGraphElem> cityes;
} Country, *PCountry;