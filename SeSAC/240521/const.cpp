#include <iostream>



int main()
{
	//const�� ������ ����� ��
	int Number = 100;
	int Number1 = 300;

	// ������ ���� ���� ��, ����Ÿ�� ���ʿ� const�� ���� ��� 
	// �����ϴ� ����� ���� ������ �� ����
	// �����ϴ� ��� ������ ����
	const int* Pointer = &Number;
	//*Pointer = 200;			// error
	Pointer = &Number1;


	// ������ ���� ���� ��, ����Ÿ�� �����ʿ� const�� ���� ���
	// �����ϴ� ����� ���� ������ �� ����
	// �����ϴ� ��� ������ �Ұ���
	int* const Pointer2 = &Number;
	*Pointer2 = 500;
	//Pointer2 = &Number1;		// error


	// �� ������ ������ Ư���� ��� ����. ���� ������ ��� ����
	// ������ ���� ���� ��, ����Ÿ�� ���ʰ� �����ʿ� const�� ���� ���
	// �����ϴ� ����� ���� ������ �� ����
	// �����ϴ� ��� ���浵 �Ұ���
	const int* const Pointer3 = &Number;
	//Pointer3 = &Number1;		// error
	//*Pointer3 = 400;			// error


	int* Pointer4 = &Number;
	int** PointerPointer = &Pointer4;

	const int a = 10;
	int b = a + a;
	int c = b + b;




	return 0;
}