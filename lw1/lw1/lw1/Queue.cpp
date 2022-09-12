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
	cout << "������� �������� � ������� (����������, �������� Enter). ��� ���������� ����� ������� ������ '~'" << endl;
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
		cout << "���������� �������� ������� � �������. ������ NULL" << endl;
		return;
	}
	string elem;
	cin >> elem;
	Queue* currElemPtr = startPtr;

	//��������� � ��������� ������� �������
	while (currElemPtr->nextElement != NULL)
	{
		currElemPtr = currElemPtr->nextElement;
	}
	
	//������� ����� ������� �������
	currElemPtr->nextElement = new Queue;
	currElemPtr = currElemPtr->nextElement;
	
	currElemPtr->nextElement = NULL;
	currElemPtr->name = elem;

	cout << "������� " << elem << " �������� � �������" << endl;
}

Queue* RemoveElementFromQueue(Queue* startPtr)
{
	if (startPtr == NULL)
		return NULL;
	Queue* result = startPtr->nextElement;
	cout << "������� " << startPtr->name << " ������ �� �������" << endl;
	free(startPtr);

	return result;
}