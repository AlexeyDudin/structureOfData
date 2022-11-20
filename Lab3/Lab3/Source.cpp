//23. Имеется  сеть  автомобильных  дорог. Для каждой  дороги
//известна ее длина.Один из городов является столицей.Требуется
//вывести список длин вторых по минимальности путей из столицы  в
//другие города.Допускается  присутствие  циклических  путей.В
//некоторые города вторых путей может не оказаться(12).
// Дудин Алексей, ИПС 2021-2023, 2022 г., Visual Studio 2022
//Использовать алгоритм Йена для поиска второго пути, а также алгоритм Дейкстры для поиска кратчайшего

#include "FileWorker.h";
#include "GraphWorker.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	Country myCountry = ReadGraph("input.txt");
	cout << "Все пути:" << endl;
	PrintGraph(myCountry);

	cout << endl;
	
	PrintAllPaths(myCountry);

	cout << endl << "Вторые по длинне пути до городов из столицы:" << endl;
	PrintSecondLenghtPath(myCountry);
	system("pause");
}