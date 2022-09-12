#pragma once
#include <string>

using namespace std;

typedef struct _queueStruct {
	string name;
	_queueStruct *nextElement;
} Queue, *PQueue;

void PrintQueue(Queue* startPtr);

Queue* AddQueue();

void AddElementToQueue(Queue* startPtr);

Queue* RemoveElementFromQueue(Queue* startPtr);
