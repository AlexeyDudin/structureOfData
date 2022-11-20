#include "TreeWorker.h"

void PrintSensationNews(PTree winner, PTree outer)
{
	cout << "��������!: " << endl;
	cout << "����� " << winner->name << " (" << winner->quantity << ") ������� � " << outer->name << " (" << outer->quantity << ")" << endl;
}

void FillWinner(PTree parent, vector<PTree>* sensations)
{
	////Ver 1: �� ��������
	//parent->name = parent->first->quantity > parent->second->quantity ? parent->first->name : parent->second->name;
	//parent->quantity = parent->first->quantity > parent->second->quantity ? parent->first->quantity : parent->second->quantity;

	//Ver 2: ������ ����������� ��������
	long res1 = rand();
	long res2 = rand();
	res1 = res1 % ((long)(parent->first->quantity * 100));
	res2 = res2 % ((long)(parent->second->quantity * 100));

	/*cout << "�������� ���������� �� " << parent->first->name << " (" << parent->first->quantity << ") 1 " << endl
		<< parent->second->name << " (" << parent->second->quantity << ")" << endl;*/
	
	//long res1 = 0, res2 = 0;
	//int res = 0;
	//cin >> res;
	//if (res == 1)
	//	res1 = 1;
	//else
	//	res2 = 1;

	parent->name = res1 > res2 ? parent->first->name : parent->second->name;
	parent->quantity = res1 > res2 ? parent->first->quantity : parent->second->quantity;

	//���� �� �������� ����� �� ������ ��� �������� - �������� ��������
	if ((parent->first->quantity > parent->second->quantity) && (parent->quantity != parent->first->quantity))
		(*sensations).push_back(parent);
		//PrintSensationNews(parent->second, parent->first);
	if ((parent->second->quantity > parent->first->quantity) && (parent->quantity != parent->second->quantity))
		(*sensations).push_back(parent);
		//PrintSensationNews(parent->first, parent->second);
}

PTree GetWinner(vector<PTree> input, vector<PTree> *sensations)
{
	vector<PTree> tmp1 = input, tmp2;
	while (tmp1.size() != 1)
	{
		tmp2.clear();
		for (int i = 0; i < tmp1.size(); i = i + 2)
		{
			PTree first = tmp1[i];
			PTree second = tmp1[i + 1];

			PTree parent = new Tree;
			parent->first = first;
			parent->second = second;
			parent->parent = NULL;
			FillWinner(parent, sensations);

			first->parent = parent;
			second->parent = parent;

			tmp2.push_back(parent);
		}

		tmp1 = tmp2;
	}
	cout << endl;
	return tmp1[0];
}

void GetCountOfInside(PTree root, int* count)
{
	if (root != NULL)
	{
		(*count)++;
		GetCountOfInside(root->first, count);
	}
}

void PrintTree(PTree root, int countTabs)
{
	if (root != NULL)
	{
		PrintTree(root->first, countTabs - 1);
		
		for (int i = 0; i < countTabs - 1; i++)
			cout << "\t";
		if (countTabs != 0)
			cout << "    |---" << root->name << " (" << root->quantity << ")" << endl;
		else 
			cout << root->name << " (" << root->quantity << ")" << endl;

		PrintTree(root->second, countTabs - 1);
	}
}

void GetSensation(PTree root, float* raznica, PTree *result)
{
	if (root != NULL && root->first != NULL && root->second != NULL)
	{
		if (abs(root->first->quantity - root->second->quantity) > (*raznica))
		{
			(*result) = root;
			(*raznica) = abs(root->first->quantity - root->second->quantity);
		}
		GetSensation(root->first, raznica, result);
		GetSensation(root->second, raznica, result);
	}
}

void PrintSensation(vector<PTree> sensations)
{
	if (sensations.size() == 0)
		cout << "��� ��������" << endl;
	else
	{
		PTree mostSensation = NULL;
		cout << "��������!" << endl;
		for (int i = 0; i < sensations.size(); i++)
		{
			float mostSensationQuantity = 0;
			if (mostSensation != NULL)
				mostSensationQuantity = abs(mostSensation->first->quantity - mostSensation->second->quantity);
			float currSensationQuantity = abs(sensations[i]->first->quantity - sensations[i]->second->quantity);
			if (mostSensation == NULL || (mostSensationQuantity < currSensationQuantity))
			{
				mostSensation = sensations[i];
			}

			if (sensations[i]->first->quantity > sensations[i]->second->quantity)
			{
				cout << "����� " << sensations[i]->second->name << " (" << sensations[i]->second->quantity << ") ������� � " << sensations[i]->first->name << " (" << sensations[i]->first->quantity << ") � �������� " << abs(sensations[i]->first->quantity - sensations[i]->second->quantity) << endl;
			}
			else
			{
				cout << "����� " << sensations[i]->first->name << " (" << sensations[i]->first->quantity << ") ������� � " << sensations[i]->second->name << " (" << sensations[i]->second->quantity << ") � �������� " << abs(sensations[i]->first->quantity - sensations[i]->second->quantity) << endl;
			}
		}
		if (mostSensation != NULL)
			cout << "����� ������������ �����:" << mostSensation->first->name << " � " << mostSensation->second->name << endl;
	}
	/*float raznica = 0;
	PTree sensationParent = NULL;
	GetSensation(root, &raznica, &sensationParent);
	if (sensationParent != NULL)
	{
		cout << "������ ������� " << sensationParent->first->name << " � " << sensationParent->second->name << " ����� ����������� ������� �����: (" << raznica << ")" << endl;
	}
	else
		cout << "��� ��������" << endl;*/
}

void RecourceDelete(PTree *root)
{
	if ((*root) != NULL)
	{
		RecourceDelete(&(*root)->first);
		RecourceDelete(&(*root)->second);
		delete(*root);
		root = NULL;
	}
}

void DeleteTree(PTree *root)
{
	RecourceDelete(root);
}
