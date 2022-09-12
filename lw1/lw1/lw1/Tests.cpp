#include "Tests.h"
#include "Queue.h"

void TestAddStack()
{
}

void TestAddQueue()
{
	//BAD
	AddElementToQueue(NULL);

	//GOOD
	Queue* result = AddQueue();
}

void TestRemoveStack()
{
}

void TestRemoveQueue()
{
}

void TestRemoveAll()
{
}

void TestAll()
{
	//Test1 BAD Add queue in NULL stack
	TestAddQueue();

	//Test2 GOOD Add stack and then Add queue
	TestAddStack();
	TestAddQueue();

	//TEST 3 BAD
	TestRemoveQueue();
}
