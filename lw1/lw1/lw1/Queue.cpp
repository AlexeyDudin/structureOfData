#include "Queue.h"
#include <iostream>

void PrintQueue(Queue* startQueuePtr)
{
	Queue* currQueueElem = startQueuePtr;
	while (currQueueElem != NULL)
	{
		cout << currQueueElem->name;
		if (currQueueElem->nextElement != NULL)
			cout << " - ";
		currQueueElem = currQueueElem->nextElement;
	}
}

Queue* AddQueue()
{
	system("cls");
	string elemName;
	Queue* startQueuePtr = NULL;
	Queue* currQueuePtr = NULL;
	cout << "¬ведите элементы в очередь (ѕоочередно, раздел€€ Enter). ƒл€ завершени€ ввода введите символ '~'" << endl;
	do
	{
		cin >> elemName;
		if (elemName == "~")
			break;
		if (startQueuePtr == NULL)
		{
			currQueuePtr = new Queue;// = malloc(sizeof Queue);
			startQueuePtr = currQueuePtr;
		}
		else
		{
			currQueuePtr->nextElement = new Queue;
			currQueuePtr = currQueuePtr->nextElement;
		}
		currQueuePtr->name = elemName;
		currQueuePtr->nextElement = NULL;
	} while (elemName != "~");
	return startQueuePtr;
}

void AddElementToQueue(Queue* startPtr)
{
	if (startPtr == NULL)
	{
		cout << "Ќевозможно добавить элемент в очередь. —сылка NULL" << endl;
		return;
	}
	string elem;
	cin >> elem;
	Queue* currElemPtr = startPtr;

	//ѕереходим в последний элемент очереди
	while (currElemPtr->nextElement != NULL)
	{
		currElemPtr = currElemPtr->nextElement;
	}
	
	//—оздаем новый элемент очереди
	currElemPtr->nextElement = new Queue;
	currElemPtr = currElemPtr->nextElement;
	
	currElemPtr->nextElement = NULL;
	currElemPtr->name = elem;

	cout << "Ёлемент " << elem << " добавлен в очередь" << endl;
}

Queue* RemoveElementFromQueue(Queue* startPtr)
{
	if (startPtr == NULL)
		return NULL;
	Queue* result = startPtr->nextElement;
	cout << "Ёлемент " << startPtr->name << " удален из очереди" << endl;
	free(startPtr);

	return result;
}