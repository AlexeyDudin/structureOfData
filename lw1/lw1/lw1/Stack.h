#pragma once
#include "Queue.h"
typedef struct _stackStructure
{
	Queue *element;
	_stackStructure *next;
} Stack, *PStack;

void PrintAllStack();

void AddQueueToStack();

void AddElementToQueue();

void RemoveFromQueue();

void RemoveFromStack();

void RemoveAllStack();