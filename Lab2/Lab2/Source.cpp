//21. ���������  ������  ��������  ��  �����������  ������� �
//�����������.��������  �������  �������  ������.����������
//�������  ��������  �  �������  ������.������������� ��������
//������ ������ ����������, ������� ������������� ������ ������.
//���������  ����������  �������  ����������  �������(����� ���
//	����������, ����������� ��������������� �����, �������������
//	���  ����� ���������� ������� ���, ����� ��� �� ����������� �
//	������ ������� �  �.�.), ��������  �  ���������  ����  ������
//	������������  �������, ������ ������ �������� �������, �����
//	��������  �����   �   ������   ���������.����������   �����
//	������������  ��������� �� ������������ ������� ���������(14).
//  ����� �������, ��� 2021-2023, 2022 �., Visual Studio 2022

#include "FileReader.h"
#include "VectorWorker.h"
#include "TreeWorker.h"
#include <time.h>

void main()
{
	srand((unsigned)time(NULL));

	setlocale(LC_ALL, "Russian");
	vector<PTree> readFromFileUsers = ReadFile("input.txt");
	if (readFromFileUsers.size() == 0)
	{
		system("pause");
		return;
	}
	//readFromFileUsers = SortVector(readFromFileUsers);
	readFromFileUsers = SortByDescending(readFromFileUsers);
	SortVector(&readFromFileUsers);
	vector<PTree> sensations;
	PTree winner = GetWinner(readFromFileUsers, &sensations);
	int countTabs = 0;
	GetCountOfInside(winner, &countTabs);
	PrintTree(winner, countTabs - 1);

	PrintSensation(sensations);

	DeleteTree(&winner);
	system("pause");
}