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
		}

		// sort
		// �������� ����(������ -> ū��), �������� ����(ū�� -> ������)
		// selection sort, bubble sort ���..
		// 1��ĭ�� ������ ĭ�� ���� ��, ���� ���ڰ� �߰ߵǸ� swap (�������� ����)
		// 2��ĭ�� �� �� ������ ĭ ���� ��, ���� ���ڰ� �߰ߵǸ� swap
		// n-1�� ĭ���� ���� ����
		// �����Ͱ� n���� ��, n-1�� * (n - 1)!�� ����
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