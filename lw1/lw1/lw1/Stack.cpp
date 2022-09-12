#include "Stack.h"
#include <iostream>

using namespace std;

Stack* stackStartPtr = NULL;

void PrintAllStack()
{
	Stack* currStackElement = stackStartPtr;
	while (currStackElement != NULL)
	{
		PrintQueue(currStackElement->element);
		cout << endl;
		if (currStackElement->next != NULL)
			cout << "|" << endl;
		currStackElement = currStackElement->next;
	}
	cout << endl;
}

void AddQueueToStack()
{
	Queue* result = AddQueue();
	if (result != NULL)
	{
		Stack* currStackPtr = new Stack;
		currStackPtr->next = stackStartPtr;
		stackStartPtr = currStackPtr;
		
		stackStartPtr->element = result;
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
		cout << "���������� �������� �������, ����� � ����� ��� �� ������ ��������";
	else
		AddElementToQueue(stackStartPtr->element);
}

void RemoveFromStack()
{
	if (stackStartPtr == NULL)
	{
		cout << "���������� ������� ������� �� �����. ���� ����" << endl;
		return;
	}
	Stack* currStackPtr = stackStartPtr->next;
	//������� �������� �������
	while ((stackStartPtr->element = RemoveElementFromQueue(stackStartPtr->element)) != NULL)
	{
	}
	cout << "��������� ������� ����� ������" << endl;
	free(stackStartPtr);
	stackStartPtr = currStackPtr;
}

void RemoveFromQueue()
{
	stackStartPtr->element = RemoveElementFromQueue(stackStartPtr->element);
	if (stackStartPtr->element == NULL)
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