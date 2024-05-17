#include <iostream>
#include <time.h>

int main()
{
	// ���� :	������ ��
	// rand();	���� ����
	srand(time(NULL));
	rand();		// �� ���� �ִ� ������, �Ҽ��� ��°�ڸ� ���������ۿ� �ȵ�. �����Ѱ� �ȵ�, rand�ι� ���ų� �ؾ���
	std::cout << rand() << std::endl;

	// 0 ~ 100 ������ ������ ���� ���
	std::cout << rand() % 101 << std::endl;

	// 100 ~ 200 ������ ������ ���� ���
	std::cout << rand() % 101 + 100 << std::endl;

	// �ּҰ��ݷ� ~ �ִ���ݷ� ������ ������ ���ݷ� ���
	int AttackMin = 100;
	int AttackMax = 300;
	int Attack = rand() % (AttackMax - AttackMin + 1) + AttackMin;
	std::cout << "���ݷ� : " << Attack << std::endl;

	// 0 ~ 100 ������ ���� �Ҽ��� 2��° �ڸ����� ���ؾ� ��
	float Percent = rand() % 10001 / 100.0f;
	std::cout << Percent << std::endl;

	if (Percent <= 0.01f)
	{
		std::cout << "����" << std::endl;
	}
	else
	{
		std::cout << "����" << std::endl;
	}

	/*
	�ݺ��� : ���� �ڵ带 ������ �ݺ��ؼ� ���۽����� �� ���
	for, while, do while

	for (�ʱⰪ; ���ǽ�; ������)
	{
		�ݺ��Ҷ� ������ �ڵ�
	}
	�ʱⰪ : for���� ���۵� �� 1���� ����
	���ǽ�, ������ : for���� ���۵Ǵ� ���� ��� ����

	���ǽ��� true�̸� �ڵ尡 ����, false�̸� for�� ����

	�ʱⰪ -> ���ǽ�(true) -> �ڵ� -> ������ -> ���ǽ� -> ... -> ���ǽ�(false) -> for�� ����
	�ʱⰪ������ ������ ������ �� ����
	�ʱⰪ���� ����� ������ for�� ���ο����� ��� ����
	*/

	for (int i = 0; i < 10000; i++)
	{
		Percent = rand() % 10001 / 100.0f;

		std::cout << i << " : " << Percent << std::endl;
		if (Percent <= 0.01f)
		{
			break;
		}
	}

	// ��ø for��
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				// �� 150�� �ݺ�
			}
		}
	}


	// while��
	// while (���ǽ�)
	// {
	//		�ݺ��� �ڵ�
	// }
	// ���ǽ��� false�� �ǰų� break�� ������ while���� ��������

	int Number = 0;
	while (Number < 10)
	{
		++Number;
	}

	// do while��
	// do
	// {
	//		������ �ڵ�
	// } while(���ǽ�);
	// �ڵ带 �� �� ������ �� while�� ���� üũ, true�� �ݺ�, false�� while�� ����

	return 0;
}