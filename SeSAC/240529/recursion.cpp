#include <iostream>

/*
����Լ� : �ڱ� �ڽ��� ȣ���ϴ� �Լ�
�ݺ����� ���� �Լ� call�� �ݺ��Ͽ� stack�� ��� ���̰� ��
return �� ������ �߰����� �ӽ� ��ü�� ��� ������
��Ͱ� ��� ���� ���� stack overflow�� �߻��� ���� ����
*/
int Factorial(int Number)
{
	if (Number == 1)
		return 1;

	return Number* Factorial(Number - 1);
}

/*
���� ��� �Լ�
�����Ϸ��� �ݺ������� �������Ѽ� ���۽�Ų��? - �𽺾���� �ؼ� Ȯ���غ���
*/
int Factorial_Tail(int Number, int Total = 1)
{
	if (Number == 1)
		return Total;

	return Factorial_Tail(Number - 1, Number * Total);
}


int main()
{
	std::cout << Factorial(5) << std::endl;

	int number = 5;
	int result = 1;
	while (number > 1)
	{
		result *= number;
		--number;
	}
	std::cout << result << std::endl;

	std::cout << Factorial_Tail(5) << std::endl;

	return 0;
}