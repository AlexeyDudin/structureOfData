#include "Queue.h"
#include <iostream>

void PrintQueue(PQueue startQueuePtr)
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

PStack AddQueue()
{
	system("cls");
	string elemName;
	PStack stackElem = new Stack;
	stackElem->startElement = NULL;
	stackElem->endElement = NULL;
	stackElem->next = NULL;
	PQueue currQueuePtr = NULL;
	cout << "¬ведите элементы в очередь (ѕоочередно, раздел€€ Enter). ƒл€ завершени€ ввода введите символ '~'" << endl;
	do
	{
		cin >> elemName;
		if (elemName == "~")
			break;
		if (stackElem->startElement == NULL)
		{
			currQueuePtr = new Queue;
			stackElem->startElement = currQueuePtr;
			stackElem->endElement = currQueuePtr;
		}
		else
		{
			stackElem->endElement->nextElement = new Queue;
			currQueuePtr = stackElem->endElement->nextElement;
			stackElem->endElement = currQueuePtr;
		}
		currQueuePtr->name = elemName;
		currQueuePtr->nextElement = NULL;

	} while (elemName != "~");
	return stackElem;
}

void AddElementToQueue(PStack startPtr)
{
	if (startPtr == NULL)
	{
		cout << "Ќевозможно добавить элемент в очередь. —сылка NULL" << endl;
		return;
	}
	string elem;
	cin >> elem;
	startPtr->endElement->nextElement = new Queue;
	startPtr->endElement = startPtr->endElement->nextElement;

	startPtr->endElement->name = elem;
	startPtr->endElement->nextElement = NULL;
	cout << "Ёлемент " << elem << " добавлен в очередь" << endl;
}

PStack RemoveElementFromQueue(PStack startPtr)
{
	if (startPtr == NULL)
		return NULL;
	PQueue result = startPtr->startElement;
	
	if (startPtr->startElement == NULL)
		return startPtr;
	
	cout << "Ёлемент " << result->name << " удален из очереди" << endl;
	if (startPtr->startElement == startPtr->endElement)
	{
		delete(startPtr->startElement);
		startPtr->endElement = NULL;
		startPtr->startElement = NULL;
		return startPtr;
	}
	else
		startPtr->startElement = startPtr->startElement->nextElement;
	delete(result);
	return startPtr;
}