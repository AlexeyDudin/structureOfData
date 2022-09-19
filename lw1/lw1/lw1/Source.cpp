/*18. ������������  �  ��������  ������ � ������� ����������
���� �� ��������.����������   ��������   �������  ������� ��
�������   �����, ����������   �  ����������  �����, ������
����������� �����(9).*/
// ����� ������� �������
//Visual studio 2022 C++

#include <iostream>
#include <locale>
#include "Stack.h"

using namespace std;

void PrintMenu()
{
	cout << "�������� ����� ����" << endl;
	cout << "1) �������� ���� ������" << endl;
	cout << "2) �������� ������� � ����" << endl;
	cout << "3) �������� ������� � ��������� ������� �����" << endl;
	cout << "4) ������� ������� �� �������, ����������� ��������� � �����" << endl;
	cout << "5) ������� ��������� ������� �����" << endl;
	cout << "6) �������� ���� ��������" << endl;
	cout << "7) �����" << endl;
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