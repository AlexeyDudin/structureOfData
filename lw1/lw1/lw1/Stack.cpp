#include "Stack.h"
#include "StackType.h"
#include <iostream>

using namespace std;

PStack stackStartPtr = NULL;

void PrintAllStack()
{
	if (stackStartPtr == NULL)
	{
		cout << "���� ������" << endl;
		return;
	}

	PStack currStackElement = stackStartPtr;
	while (currStackElement != NULL)
	{
		PrintQueue(currStackElement->startElement);
		cout << endl;
		if (currStackElement->next != NULL)
			cout << "|" << endl;
		currStackElement = currStackElement->next;
	}
	cout << endl;
}

void AddQueueToStack()
{
	PStack stackPtr = AddQueue();
	if (stackPtr->startElement != NULL)
	{
		stackPtr->next = stackStartPtr;
		stackStartPtr = stackPtr;
		cout << "������� ��������� � ����" << endl;
	}
	else
	{
		cout << "�� ���� ������� �� ��� �������� � �������. ������� �� �������� � ����" << endl;
	}
}

void AddElementToQueue()
{
	if (stackStartPtr == NULL)
		cout << "���������� �������� �������, ����� � ����� ��� �� ������ ��������" << endl;
	else
		AddElementToQueue(stackStartPtr);
}

void RemoveFromStack()
{
	if (stackStartPtr == NULL)
	{
		cout << "���������� ������� ������� �� �����. ���� ����" << endl;
		return;
	}
	PStack currStackPtr = stackStartPtr->next;
	//������� �������� �������
	while ((stackStartPtr = RemoveElementFromQueue(stackStartPtr))->startElement != NULL)
	{
	}
	cout << "��������� ������� ����� ������" << endl;
	delete(stackStartPtr);
	stackStartPtr = currStackPtr;
}

void RemoveFromQueue()
{
	if (stackStartPtr == NULL)
	{
		cout << "���������� ������� ������� �� �������. ���� ����" << endl;
		return;
	}
	stackStartPtr = RemoveElementFromQueue(stackStartPtr);
	if (stackStartPtr->startElement == NULL)
	{
		cout << "�� �������� �� ������ �������� � �������. ������� ������� �� �����" << endl;
		RemoveFromStack();
	}
}

void RemoveAllStack()
{
	while (stackStartPtr != NULL)
		RemoveFromStack();
	cout << "���� ���� ������" << endl;
}