#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	rand();

	/*
	�迭 : ���� Ÿ���� ���� �������� �ʿ��� ��� ����� �� �ִ� ����
	�ּ� : 1����Ʈ ������ �ο���, 16���� 16�ڸ��� �ּ� ü�� ���� (16���� 1�ڸ� = 2���� 4�ڸ� = 4bit, 64bit = 16*4)
	����ִ� �ּ� ���� : �ü���� ����
	�迭 : ���ӵ� �޸� ������ �Ҵ�� (int�迭 10�� ���� ��, 40byte���� �ʿ�, 40byte��ŭ ���ӵ� �޸𸮿� ������ ����� ��)

	ù ��° ����� �ּҸ� ���� ���� ����� �ּҸ� �� �� ����

	�迭 ���� ���
	����Ÿ�� �迭��[����];
	
	int Array[10];

	�迭�� �� ��ҿ� �����ϱ� ���� �ε��� ���
	�ε����� 0 ~ ���� - 1 ���� ����
	�ε����� ���� ���� �������� ����ؾ� ��

	Array[2] = 300;

	*** �迭�� �̸��� �ش� �迭�� ���� �޸� �ּ��̴� ***
	*/

	//int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int Array[10] = { 1,2,3,4 };	// 4�� index���� ��� 0���� �ʱ�ȭ
	int Array[10] = {};	// ��� ��Ҹ� 0���� �ʱ�ȭ

	for (int i = 0; i < 10; i++)
	{
		Array[i] = 0;
	}

	Array[2] = 300;
	// Array[20] = 500;

	std::cout << Array[0] << std::endl;
	std::cout << Array[2] << std::endl;
	std::cout << Array << std::endl;


	// ������ �迭
	int Array1[10][5] = {};	// 50��¥�� 1���� �迭�̶� �޸� ���°� �Ȱ���
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// �ٹ�ȣ * ���ΰ��� + ���ι�ȣ
			Array1[i][j] = i * 5 + j;
		}
	}

	int Array2[50] = {};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Array2[i * 5 + j] = i * 5 + j + 1;
		}
	}


	/*
	shuffle
	*/
	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 50;
		int Index2 = rand() % 50;

		// swap
		int Temp = Array2[Index1];
		Array2[Index1] = Array2[Index2];
		Array2[Index2] = Temp;
	}

	// �ܼ�â ��� ����
	system("cls");
	for (auto a : Array2)
	{
		std::cout << a << std::endl;
	}


	return 0;
}