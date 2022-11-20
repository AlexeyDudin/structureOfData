#include "VectorWorker.h"

PTree GetMaxElem(vector<PTree> input)
{
    PTree result = input[0];

    for (int i = 0; i < input.size(); i++)
    {
		if (result->quantity < input[i]->quantity)
			result = input[i];
    }

    return result;
}

PTree GetMinElem(vector<PTree> input)
{
    PTree result = input[0];

    for (int i = 0; i < input.size(); i++)
    {
        if (result->quantity > input[i]->quantity)
            result = input[i];
    }

    return result;
}

vector<PTree> RemoveElemFromVector(PTree elem, vector<PTree> input)
{
    vector<PTree> result;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != elem)
            result.push_back(input[i]);
    }
    return result;
}

void SortVector(vector<PTree> *input)
{
	if ((*input).size() != 2)
	{
		vector<PTree> first;
		vector<PTree> second;

		int perekluchatel = 1;
		for (int i = 0; i < (*input).size(); i++, perekluchatel++)
		{
			if (perekluchatel == 4)
				perekluchatel = 0;
			if (perekluchatel < 2)
				first.push_back((*input)[i]);
			else
				second.push_back((*input)[i]);
		}

		SortVector(&first);
		SortVector(&second);

		(*input).clear();
		for (int i = 0; i < first.size(); i++)
		{
			(*input).push_back(first[i]);
		}
		for (int i = 0; i < second.size(); i++)
		{
			(*input).push_back(second[i]);
		}
	}
}

vector<PTree> SortByDescending(vector<PTree> input)
{
	vector<PTree> result = input;
	//BubbleSort в большую сторону
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = i; j < result.size(); j++)
		{
			if (result[i]->quantity < result[j]->quantity)
			{
				PTree tmp = result[i];
				result[i] = result[j];
				result[j] = tmp;
			}
		}
	}
	return result;
}

vector<PTree> SortVector(vector<PTree> input)
{
	//// Sort ver 1
 //   vector<PTree> tmp = input;
 //   vector<PTree> result;

 //   while (tmp.size() != 0)
 //   {
 //       PTree elem = GetMaxElem(tmp);
 //       result.push_back(elem);
 //       tmp = RemoveElemFromVector(elem, tmp);

 //       elem = GetMinElem(tmp);
 //       result.push_back(elem);
 //       tmp = RemoveElemFromVector(elem, tmp);
 //   }
 //   return result;

	////Sort ver 2
	//vector<PTree> result = input;
	////BubbleSort
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (int j = i; j < result.size(); j++)
	//	{
	//		if (result[i]->quantity < result[j]->quantity)
	//		{
	//			PTree tmp = result[i];
	//			result[i] = result[j];
	//			result[j] = tmp;
	//		}
	//	}
	//}

	//for (int i = 1; i < result.size() / 2; i = i + 2)
	//{
	//	PTree tmp = result[i];
	//	result[i] = result[result.size() - i];
	//	result[result.size() - i] = tmp;
	//}

	//Sort ver 3
	vector<PTree> result = input;
	//BubbleSort в большую сторону
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = i; j < result.size(); j++)
		{
			if (result[i]->quantity > result[j]->quantity)
			{
				PTree tmp = result[i];
				result[i] = result[j];
				result[j] = tmp;
			}
		}
	}
	//2-ой элемент меняем с последним местами
	PTree tmp = result[1];
	result[1] = result[result.size() - 1];
	result[result.size() - 1] = tmp;

	return result;
}
