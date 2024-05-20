#include <iostream>
#include <time.h>

/*
로또 프로그램
1 ~ 45 사이의 숫자가 있고 이를 섞어 줌
사용자는 원하는 게임 수를 입력
해당 수만큼 번호 6개를 랜덤하게 뽑아줌
*/

int main()
{
	int lotto[45] = {};

	int input;
	std::cout << "게임 수 : ";
	std::cin >> input;

	srand(time(NULL));
	rand();

	int current = 1;

	while (input-- > 0)
	{
		std::cout << current++ << "회차:\t";
		// initialize
		for (int i = 0; i < 45; i++)
		{
			lotto[i] = i + 1;
		}

		// shuffle
		for (int i = 0; i < 6; i++)
		{
			int random = rand() % (45 - i) + i;
			int temp = lotto[i];
			lotto[i] = lotto[random];
			lotto[random] = temp;
		}

		// sort
		// 오름차순 정렬(작은거 -> 큰거), 내림차순 정렬(큰거 -> 작은거)
		// selection sort, bubble sort 등등..
		// 1번칸과 나머지 칸을 전부 비교, 작은 숫자가 발견되면 swap (오름차순 기준)
		// 2번칸과 그 뒤 나머지 칸 전부 비교, 작은 숫자가 발견되면 swap
		// n-1번 칸까지 전부 수행
		// 데이터가 n개일 때, n-1번 * (n - 1)!번 수행
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (lotto[i] > lotto[j])
				{
					int temp = lotto[i];
					lotto[i] = lotto[j];
					lotto[j] = temp;
				}
			}
		}

		// print
		for (int i = 0; i < 6; i++)
		{
			std::cout << lotto[i] << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}