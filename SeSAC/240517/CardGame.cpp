#include <iostream>
#include <time.h>

/*
¦���߱� ����
1 ~ 10 ���� ���ڰ� 2���� ����
���ڸ� ���� ������
*�� 10 x 2�� ���
����ڴ� 2���� index�� �Է��ؼ�
2���� �ε����� ���� ���� ��� �ش� �κ��� ���ڷ� ���
10���� �� ���߸� ���� ����
-1 �Է� ��, ���� ����
*/

int main()
{
	//20ĭ ���� �迭, 20ĭ bool �迭 ����
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
		std::cout << "���� ī�� �� : " << CardLeft << std::endl;

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
			std::cout << "�����մϴ�! Ŭ�����߽��ϴ�!" << std::endl;
			break;
		}

		// user input
		int input1, input2;
		std::cout << "�Է�(0 ~ 19) : ";
		std::cin >> input1 >> input2;

		// check exit input
		if (input1 == -1 || input2 == -1)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl << std::endl;
			break;
		}
		else if (input1 < 0 || input1 > 19 || input2 < 0 || input2 > 19)
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl << std::endl;
			system("pause");
			continue;
		}
		else if (input1 == input2)
		{
			std::cout << "������ ī��� ������ �Ұ����մϴ�." << std::endl << std::endl;
			system("pause");
			continue;
		}
		else if (Check[input1] || Check[input2])
		{
			std::cout << "�̹� ���� ī�带 �����Ͽ����ϴ�." << std::endl << std::endl;
			system("pause");
			continue;
		}

		// check card
		if (Card[input1] == Card[input2])
		{
			Check[input1] = true;
			Check[input2] = true;
			CardLeft -= 2;
			std::cout << "�¾ҽ��ϴ�!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Ʋ�Ƚ��ϴ�!" << std::endl;
			std::cout << input1 << "��° ī�� ���� : " << Card[input1] << std::endl;
			std::cout << input2 << "��° ī�� ���� : " << Card[input2] << std::endl;
			std::cout << std::endl;
		}
	}

	return 0;
}