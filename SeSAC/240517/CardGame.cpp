#include <iostream>
#include <time.h>

/*
짝맞추기 게임
1 ~ 10 까지 숫자가 2개씩 존재
숫자를 골고루 섞어줌
*을 10 x 2로 출력
사용자는 2개의 index를 입력해서
2개의 인덱스의 값이 같을 경우 해당 부분은 숫자로 출력
10개의 페어를 맞추면 게임 종료
-1 입력 시, 게임 종료
*/

int main()
{
	//20칸 숫자 배열, 20칸 bool 배열 생성
	const int CardSize = 20;
	int Card[CardSize];
	bool Check[CardSize];
	int CardLeft = CardSize;

	// initialize
	for (int i = 0; i < CardSize; i++)
	{
		Card[i] = i / 2 + 1;
		Check[i] = false;
	}

	// shuffle
	srand(time(NULL));
	rand();
	for (int i = CardSize; i > 0; i--)
	{
		int random = rand() % i;
		int temp = Card[i - 1];
		Card[i - 1] = Card[random];
		Card[random] = temp;
	}

	while (true)
	{
		//system("cls");
		std::cout << "남은 카드 수 : " << CardLeft << std::endl;

		// print back of the card
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < CardSize / 2; j++)
			{
				int CurrentNum = i * 10 + j;
				if (Check[CurrentNum])
				{
					std::cout << Card[CurrentNum] << " ";
				}
				else
				{
					std::cout << "* ";
				}
			}
			std::cout << std::endl;
		}

		// check game over
		if (CardLeft <= 0)
		{
			std::cout << "축하합니다! 클리어했습니다!" << std::endl;
			break;
		}

		// user input
		int input1, input2;
		std::cout << "입력(0 ~ 19) : ";
		std::cin >> input1 >> input2;

		// check exit input
		if (input1 == -1 || input2 == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl << std::endl;
			break;
		}
		else if (input1 < 0 || input1 > 19 || input2 < 0 || input2 > 19)
		{
			std::cout << "잘못된 입력입니다." << std::endl << std::endl;
			system("pause");
			continue;
		}
		else if (input1 == input2)
		{
			std::cout << "동일한 카드는 선택이 불가능합니다." << std::endl << std::endl;
			system("pause");
			continue;
		}
		else if (Check[input1] || Check[input2])
		{
			std::cout << "이미 열린 카드를 선택하였습니다." << std::endl << std::endl;
			system("pause");
			continue;
		}

		// check card
		if (Card[input1] == Card[input2])
		{
			Check[input1] = true;
			Check[input2] = true;
			CardLeft -= 2;
			std::cout << "맞았습니다!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "틀렸습니다!" << std::endl;
			std::cout << input1 << "번째 카드 숫자 : " << Card[input1] << std::endl;
			std::cout << input2 << "번째 카드 숫자 : " << Card[input2] << std::endl;
			std::cout << std::endl;
		}
	}

	return 0;
}