/*18. Организовать  в  основной  памяти с помощью указателей
стек из очередей.Обеспечить   операции   ведения  очереди из
вершины   стека, расширения   и  сокращения  стека, выдачи
содержимого стека(9).*/
// Дудин Алексей Юрьевич
//Visual studio 2022 C++

#include <iostream>
#include <locale>
#include "Stack.h"

using namespace std;

void PrintMenu()
{
	cout << "Выберите пункт меню" << endl;
	cout << "1) Показать весь список" << endl;
	cout << "2) Добавить очередь в стек" << endl;
	cout << "3) Добавить элемент в последнюю очередь стека" << endl;
	cout << "4) Удалить элемент из очереди, находящейся последней в стеке" << endl;
	cout << "5) Удалить последний элемент стека" << endl;
	cout << "6) Очистить стек очередей" << endl;
	cout << "7) Выход" << endl;
}


int main(int argc, char* argv[])
{
	int menuSelected = 0;
	//system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	//TestAll();

	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	PStack startStackPtr = NULL;
	do
	{
		system("cls");
		PrintMenu();
		cin >> menuSelected;
		switch (menuSelected)
		{
		case 1: 
			PrintAllStack();
			system("pause");
			break;
		case 2:
			AddQueueToStack();
			system("pause");
			break;
		case 3:
			AddElementToQueue();
			system("pause");
			break;
		case 4:
			RemoveFromQueue();
			system("pause");
			break;
		case 5:
			RemoveFromStack();
			system("pause");
			break;
		case 6:
			RemoveAllStack();
			system("pause");
			break;
		default:
			break;
		}
	} while (menuSelected != 7);
	RemoveAllStack();
	return 0;
}