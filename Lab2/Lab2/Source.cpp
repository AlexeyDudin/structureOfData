//21. Теннисный  турнир  проходит  по  олимпийской  системе с
//выбываниями.Известен  рейтинг  каждого  игрока.Результаты
//турнира  записаны  с  помощью  дерева.Первоначально задается
//только список участников, которым соответствуют листья дерева.
//Требуется  предложить  принцип  проведения  турнира(выбор пар
//	участников, организация предварительных туров, распределение
//	или  посев сильнейших игроков так, чтобы они не встречались в
//	начале турнира и  т.п.), показать  в  наглядном  виде  дерево
//	проведенного  турнира, выдать список сенсаций турнира, когда
//	побеждал  игрок   с   низшим   рейтингом.Определить   самый
//	сенсационный  результат по максимальной разнице рейтингов(14).
//  Дудин Алексей, ИПС 2021-2023, 2022 г., Visual Studio 2022

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