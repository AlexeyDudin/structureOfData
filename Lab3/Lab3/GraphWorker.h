#pragma once
#include "Country.h"

using namespace std;

void PrintGraph(Country country);
vector<vector<PPath>> FindPaths(Country country, PGraphElem from, PGraphElem to);
void PrintSecondLenghtPath(Country country);
void PrintAllPaths(Country country);