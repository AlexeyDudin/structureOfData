//23. �������  ����  �������������  �����. ��� ������  ������
//�������� �� �����.���� �� ������� �������� ��������.���������
//������� ������ ���� ������ �� ������������� ����� �� �������  �
//������ ������.�����������  �����������  �����������  �����.�
//��������� ������ ������ ����� ����� �� ���������(12).
// ����� �������, ��� 2021-2023, 2022 �., Visual Studio 2022
//������������ �������� ���� ��� ������ ������� ����, � ����� �������� �������� ��� ������ �����������

#include "FileWorker.h";
#include "GraphWorker.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	Country myCountry = ReadGraph("input.txt");
	cout << "��� ����:" << endl;
	PrintGraph(myCountry);

	cout << endl;
	
	PrintAllPaths(myCountry);

	cout << endl << "������ �� ������ ���� �� ������� �� �������:" << endl;
	PrintSecondLenghtPath(myCountry);
	system("pause");
}