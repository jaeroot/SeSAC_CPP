#include <iostream>
#include <time.h>

/*
�ζ� ���α׷�
1 ~ 45 ������ ���ڰ� �ְ� �̸� ���� ��
����ڴ� ���ϴ� ���� ���� �Է�
�ش� ����ŭ ��ȣ 6���� �����ϰ� �̾���
*/

int main()
{
	int lotto[45] = {};

	int input;
	std::cout << "���� �� : ";
	std::cin >> input;

	srand(time(NULL));
	rand();

	int current = 1;

	while (input-- > 0)
	{
		std::cout << current++ << "ȸ��:\t";
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