#include <iostream>

/*
�Լ� : Ư�� ������ �ϴ� �ڵ带 �̸� �ۼ��ϰ�, �ʿ��� �� ȣ���Ͽ� ����� �� �ִ� ����� �����ϴ� ��

��ȯŸ�� �Լ���(����)
{
}

�Լ��� �����Ǿ� �ִ� ����� ���۽�Ű�� �Լ��� ����� ��ȯ �� �� ����
��ȯŸ�� : �Լ��� ����� ��ȯ�ؾ� �� ���� Ÿ���� ����
��ȯ�� ���� : void
��ȯ�� ���� : void ���� Ÿ��
return Ű���带 �̿��ؼ� �Լ��� ����� ��ȯ�� �� �ִ�.

void�� Ÿ���� ���ٴ� �ǹ�
�Լ��� ��ȯ Ÿ���� void�� �ϸ� ����� ��ȯ���� �ʾƵ� �ȴ�.

�Լ��� : �Լ� �̸� �ۼ�

���� : �Լ��� ������ �� �ʿ��� �����͸� �Ѱ��� �������� ���
*/
void Output()
{
	std::cout << "Output Function" << std::endl;
}

int Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}
/*
�Լ� ���ο� ����� ������ ����������� �Ѵ�.
���������� �ش� �Լ� �������� ����� �����ϰ�, �Լ� �ܺο����� ����� �Ұ�����
���������� �޸� ���� �߿� �����̶�� ������ ������ �������
���������� �Լ��� ����Ǹ� �޸𸮿��� ���ŵ�
*/
void ChangeNumber(int Number)
{
	Number = 999;
}

// ���������� data������ ������ �������
int gNumber = 100;

void ChangeNumber1(int* Pointer)
{
	*Pointer = 777;
}

void SetArray(int* Array)
{
	for (int i = 0; i < 10; i++)
	{
		Array[i] = i + 1;
	}
}

int main()
{
	Output();
	std::cout << Sum(10, 20) << std::endl;

	int Number = 0;

	ChangeNumber(Number);
	std::cout << Number << std::endl;

	/*
	������ : �޸� �ּҸ� �����ϴ� ����
	��� ���� Ÿ���� ������ Ÿ�� ������ ������ �� ����
	int������ �ּҴ� int�� ������ Ÿ�� ������ �����ؾ� �Ѵ�

	����Ÿ��* �����͸�; ���� ������ �� ����
	*/
	int* Pointer = nullptr;

	// ���� �տ� &�� �ٿ��ָ� �ش� ������ �޸� �ּҸ� �ǹ���
	Pointer = &Number;

	// �������� ���� ������ �ִ� �޸� �ּҿ� �����Ͽ� ���� �����ϰų� ���ͼ� ����� �� ����
	*Pointer = 999;
	std::cout << Number << std::endl;

	ChangeNumber1(&Number);
	std::cout << Number << std::endl;

	int Array[10] = {};
	std::cout << Array << std::endl;
	
	// �迭 ���� �ּ�[�ε���]
	Array[1] = 100;

	int* PointerArray = Array;
	PointerArray[3] = 200;

	SetArray(Array);

	for (int i = 0; i < 10; i++)
	{
		std::cout << Array[i] << std::endl;
	}

	// ������ ���� : +, -�� ������
	// �������� ������ Ÿ�Կ� ������ ����
	// int �������� ��� 3�� ���ϸ� �ܼ��� �ּҰ� 3��ŭ �����ϴ� ���� �ƴ�, 3 * int�� ũ�� ��ŭ �ּҰ� �����ϰ� ��
	// index�� �����ϴ� ���� random access��� �� (�ᱹ ������ �ּ� ������)

	std::cout << PointerArray << std::endl;
	std::cout << PointerArray + 1 << std::endl;
	PointerArray[2] = 300;
	*(PointerArray + 2) = 111;
	std::cout << Array[2] << std::endl;


	return 0;
}