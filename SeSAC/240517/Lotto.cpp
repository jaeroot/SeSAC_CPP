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

			std::cout << lotto[i] << "\t";
		}
		std::cout << std::endl;
	}


	
}