#include "TreeElement.h"
#pragma once
#include <vector>
#include <iostream>
#include <math.h>

PTree GetWinner(vector<PTree> input, vector<PTree>* sensations);
void GetCountOfInside(PTree root, int *count);
void PrintTree(PTree root, int countTabs);
void PrintSensation(vector<PTree> sensations);
void DeleteTree(PTree *root);