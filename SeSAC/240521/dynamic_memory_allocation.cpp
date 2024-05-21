#include <iostream>

/*
�Լ� �����ε� : �Լ��� �̸��� ������ ���°� �ٸ� ��
������ ���� Ȥ�� Ÿ���� �ٸ� ��� �ٸ� ������ �Լ���� ���� �� �ִ�.
��ȯŸ�Ե� �Լ��� ���·� �� �� ������, �����ε����� ������ �� �� ����.
*/

void Output()
{
	std::cout << "Output Function" << std::endl;
}

void Output(int Number)
{
}

void Output(float Number)
{
}

// ��ȯ���� �����ε��� ���� x
//int Output(int Number)
//{
//}

/*
�Լ��� ����Ʈ���� : �Լ��� ���ڰ� ���� ���, ȣ�� �� �ݵ�� ���ڿ� ���� �������־�� �ߴ�.
������ ����Ʈ ���ڴ� �Լ��� ���ڿ� �⺻���� �����Ͽ� ���ڿ� ���� �����ϸ� ���޵� ���� ����ϰ�,
�������� ���� ��� �⺻���� ������ ���� ����� �� �ְ� ���ִ� ���
���ڰ� �������� ���� ���, ���� ������ ���ں��� ����Ʈ ���ڸ� ����ؾ� ��
int Num1, int Num2 2���� ���ڰ� �ִٸ�, int Num1 = 100, int Num2 �̷������� ����� �Ұ����ϴ�.
*/


int Sum(int Num1, int Num2 = 300)
{
	return Num1 + Num2;
}
int Minus(int Num1, int Num2 = 300)
{
	return Num1 - Num2;
}

// **** default ���� ��� ��, �����ε��� �����ؾ� �� ****
//float Sum(int Num1)
//{
//	return Num1 + 30;
//}

/*
�Լ� ������ : �Լ��� �ּҸ� ��� ���� ����
�ڵ� ����(�޸�)
�޸��� ���� ���� : stack, heap, data, code ����
�Լ� ���� ��, �ڵ� ������ �Լ� ������ ����(�ּ� ����)�� ���� �ش� ��ġ�� �����ؼ� �����ϰ� ��
�Լ� ���� ������ ������ �ʴ� �Լ� : inline �Լ�
inline Ű���带 ���̸� �����Ϸ��� ������ �� ��, �ڵ� ������ �ش� �ڵ� ������ �ٿ��־� ��
(ex. inline �Լ��� getNum(){return Num}�� �ִٸ� �̰� ȣ���ϴ� �κп� �����ٰ� �ڵ�ȭ ���ѹ���)
������ ����ų� �޸� ������ ��� ���� �ӵ��� ����Ǵ� ������ ������, �ڵ尡 ��� ������ �ð��� ��ƸԴ� ������ ����


******
****** �Լ� ȣ�� �Ծ� ****** << �ݵ�� �˾ƺ� ��
******


�Ϲ������� ������ �ܺο� �ִ� �Լ� : ���� �Լ�
�Լ��� �̸� = �Լ��� �ּ�
�Լ��� ȣ���� �Լ��ּ�(�μ�) �� ����.

*/

struct FButton
{
	// Ŭ���� ���õ� ���� ����
	void (*ClickFunc)();
};

void Close()
{
	std::cout << "Close" << std::endl;
}

void Compile()
{
	std::cout << "Compile" << std::endl;
}

int main()
{
	std::cout << Sum(200) << std::endl;
	std::cout << Sum(10, 233) << std::endl;

	std::cout << Sum << std::endl;

	// �Լ� ������ ������
	// �Լ��� ���´� ��ȯŸ�԰� ���ڿ� ������ �޴´�.
	// �Լ��� �̸��� �Լ��� ���¿� ������ ����.
	// ��ȯŸ�� (*�����͸�)(����Ÿ��);
	// ���� ���� �Լ� ������ Ÿ���� ������ ������ �� �ִ�.
	
	int (*Func)(int, int) = Sum;
	int (*FuncArray[10])(int, int);

	FuncArray[0] = Sum;
	FuncArray[1] = Minus;

	FuncArray[0](10, 20);
	FuncArray[1](10, 20);

	// �Լ��ּ�(�μ�)
	Sum(10, 20);
	std::cout << Func(10, 20) << std::endl;

	Func = Minus;

	std::cout << Func(10, 20) << std::endl;

	// ��ư �Է� ��, Ŭ���ϴ� ����� ����
	// ��ư�� �Լ� �����͸� �ϳ� ���� ��
	// â�� �����Ű�� ��� ���� ��, �Լ� �����͸� ������

	// �浹ó�� ��, �浹 ���� ����� �����, �Լ� �����͸� ���� �پ��� ȿ���� ���� �� �ְ� ��

	FButton CloseButton, CompileButton;
	CloseButton.ClickFunc = Close;
	CompileButton.ClickFunc = Compile;

	// CloseButton Ŭ�� ��
	CloseButton.ClickFunc();

	// CompileButton Ŭ�� ��
	CompileButton.ClickFunc();

	int a;
	int* b = new int;

	std::cout << &a << std::endl;
	std::cout << b << std::endl;
	delete b;


	return 0;
}