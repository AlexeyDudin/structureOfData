#pragma once
#include <string>
//#include "Stack.h"

using namespace std;

typedef struct _queueStruct {
	string name;
	_queueStruct* nextElement;
} Queue, * PQueue;