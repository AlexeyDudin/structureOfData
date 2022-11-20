#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <math.h>

bool IsCanUse(int countElems)
{
	int tmp = countElems;
	while (tmp != 1)
	{
		int tmp2 = tmp >> 1;
		tmp2 = tmp2 << 1;
		if ((tmp2 != 1) && (tmp != tmp2))
			return false;
		tmp = tmp2 >> 1;
	}
	return true;
}

std::vector<PTree> ReadFile(string fileName)
{
	std::vector<PTree> result;

	ifstream tournirFile;
	tournirFile.open(fileName);

	if (!tournirFile.is_open())
	{
		cout << "Ошибка открытия файла " << fileName << endl;
		return vector<PTree>();
	}

	int countElems = 0;
	while (!tournirFile.eof())
	{
		PTree newElem = new Tree;
		tournirFile >> newElem->name;
		tournirFile >> newElem->quantity;
		newElem->first = NULL;
		newElem->parent = NULL;
		newElem->second = NULL;
		result.push_back(newElem);
		countElems++;
	}

	if (!IsCanUse(countElems))
	{
		cout << "Не верное количество участников! Должно быть кратно степени 2" << endl;
		return vector<PTree>();
	}

	return result;
}
