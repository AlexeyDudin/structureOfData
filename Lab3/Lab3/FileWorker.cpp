#include "FileWorker.h"

Country ReadGraph(string name)
{
	Country result;
	result.capital = new GraphElem;
	ifstream file;
	file.open(name);
	if (!file.good())
	{
		cout << "Ошибка открытия файла " << name << endl;
		return result;
	}

	//считываем столицу
	file >> result.capital->name;
	result.capital->isReturned = false;
	result.cityes.push_back(result.capital);

	//считываем все пути
	while (!file.eof())
	{
		string fromStr = "";
		string toStr = "";

		file >> fromStr;
		file >> toStr;

		PGraphElem from = NULL;
		PGraphElem to = NULL;

		for (int i = 0; i < result.cityes.size(); i++)
		{
			if (result.cityes[i]->name == fromStr)
				from = result.cityes[i];
			if (result.cityes[i]->name == toStr)
				to = result.cityes[i];
		}

		/*if (fromStr == result.capital->name)
			from = result.capital;
		else if (toStr == result.capital->name)
			to = result.capital;
		
		for (int i = 0; i < result.paths.size(); i++)
		{
			if (result.paths[i]->left->name == fromStr && from == NULL)
				from = result.paths[i]->left;
			else if (result.paths[i]->left->name == toStr && to == NULL)
				to = result.paths[i]->left;
			else if (result.paths[i]->right->name == fromStr && from == NULL)
				from = result.paths[i]->right;
			else if (result.paths[i]->right->name == toStr && to == NULL)
				to = result.paths[i]->right;
		}*/

		if (from == NULL)
		{
			from = new GraphElem;
			from->name = fromStr;
			from->isReturned = false;
			result.cityes.push_back(from);
		}
		if (to == NULL)
		{
			to = new GraphElem;
			to->name = toStr;
			to->isReturned = false;
			result.cityes.push_back(to);
		}

		PPath path = new Path;

		
		path->left = from;
		path->right = to;

		file >> path->size;
		result.paths.push_back(path);
	}
	
	return result;
}
