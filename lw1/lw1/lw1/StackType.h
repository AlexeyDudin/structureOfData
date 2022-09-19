#pragma once
#include "QueueType.h"
typedef struct _stackStructure
{
	_queueStruct* startElement;
	_queueStruct* endElement;
	_stackStructure* next;
} Stack, * PStack;
