#pragma once
#include "QueueType.h"
#include "StackType.h"

void PrintQueue(PQueue startPtr);

PStack AddQueue();

void AddElementToQueue(PStack startPtr);

PStack RemoveElementFromQueue(PStack startPtr);
