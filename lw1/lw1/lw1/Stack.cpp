#include "Stack.h"
#include "StackType.h"
#include <iostream>

using namespace std;

PStack stackStartPtr = NULL;

void PrintAllStack()
{
	if (stackStartPtr == NULL)
	{
		cout << "Стек пустой" << endl;
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
		cout << "Невозможно добавить элемент, когда в стеке нет ни одного элемента" << endl;
	else
		AddElementToQueue(stackStartPtr);
}

void RemoveFromStack()
{
	if (stackStartPtr == NULL)
	{
		cout << "Невозможно удалить элемент из стека. Стек пуст" << endl;
		return;
	}
	PStack currStackPtr = stackStartPtr->next;
	//Очищаем элементы очереди
	while ((stackStartPtr = RemoveElementFromQueue(stackStartPtr))->startElement != NULL)
	{
	}
	cout << "Последний элемент стека очищен" << endl;
	delete(stackStartPtr);
	stackStartPtr = currStackPtr;
}

void RemoveFromQueue()
{
	if (stackStartPtr == NULL)
	{
		cout << "Невозможно удалить элемент из очереди. Стек пуст" << endl;
		return;
	}
	stackStartPtr = RemoveElementFromQueue(stackStartPtr);
	if (stackStartPtr->startElement == NULL)
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