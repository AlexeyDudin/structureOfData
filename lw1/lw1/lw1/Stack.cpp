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
		cout << "Очередь добавлена в стек" << endl;
	}
	else
	{
		cout << "Ни один элемент не был добавлен в очередь. Элемент не добавлен в стек" << endl;
	}
}

void AddElementToQueue()
{
	if (stackStartPtr == NULL)
		cout << "Невозможно добавить элемент, когда в стеке нет ни одного элемента";
	else
		AddElementToQueue(stackStartPtr->element);
}

void RemoveFromStack()
{
	if (stackStartPtr == NULL)
	{
		cout << "Невозможно удалить элемент из стека. Стек пуст" << endl;
		return;
	}
	Stack* currStackPtr = stackStartPtr->next;
	//Очищаем элементы очереди
	while ((stackStartPtr->element = RemoveElementFromQueue(stackStartPtr->element)) != NULL)
	{
	}
	cout << "Последний элемент стека очищен" << endl;
	free(stackStartPtr);
	stackStartPtr = currStackPtr;
}

void RemoveFromQueue()
{
	stackStartPtr->element = RemoveElementFromQueue(stackStartPtr->element);
	if (stackStartPtr->element == NULL)
	{
		cout << "Не осталось ни одного элемента в очереди. Удаляем элемент из стека" << endl;
		RemoveFromStack();
	}
}

void RemoveAllStack()
{
	while (stackStartPtr != NULL)
		RemoveFromStack();
	cout << "Весь стек очищен" << endl;
}