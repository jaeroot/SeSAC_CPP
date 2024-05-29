#include <iostream>

/*
template : Ŭ����, ����ü, �Լ����� ��� ����
���ϴ� �κп��� Ÿ���� ���ϴ� Ÿ������ ������ �� �ִ� ���
template <typename ���ϴ��̸�, typename ���ϴ��̸�>
typename��� class�� �ᵵ ��
template <class ���ϴ��̸�, typename ���ϴ��̸�>
*/

template <typename T>
T Plus(T Num1, T Num2)
{
	//if (typeid(T).hash_code() == typeid(float).hash_code())

	return Num1 + Num2;
}

// ���ø��� �⺻Ÿ���� ������ �� ���� (�Լ� default ����ó�� �����ʺ���)
template <typename T = float>
T Minus(T Num1, T Num2)
{
	std::cout << typeid(T).name() << std::endl;
	return Num1 - Num2;
}

template <typename T = float>
void OutputType()
{
	std::cout << typeid(T).name() << std::endl;
}

template <typename T>
class CTemplate
{
public:
	T mData;

public:
	void Output()
	{
		std::cout << mData << std::endl;
	}

	void Output1();

	template <typename T1 = float>
	void Output2()
	{
		std::cout << typeid(T).name() << std::endl;
		std::cout << typeid(T1).name() << std::endl;
	}
};

template <typename T>
void CTemplate<T>::Output1()
{

}


/*
��Ÿ�� ���ø� ���� : ���� Ÿ���� �ƴ� ������ Ÿ���� ������
�Ʒ��� ���� �����ϸ� Count�� ����� ��
#define Count 500, #define Count 100�� �ٸ� �� : define�� �̸��� �ߺ��ż� ������ �� ��
�̷��� ���� ��ü���� ���� Count��� ��� �̸����� �ٸ� ���� �� �� ����
*/
template <typename T, int Count = 1000>
class CTemplate1
{
public:
	int mArray[Count];

public:
	void Output()
	{
		std::cout << typeid(T).name() << "," << typeid(Count).name() << std::endl;
	}
};

template <typename T, int Count = 100>
class CArray
{
public:
	CArray()
	{
		mArray = new T[Count];
	}

	~CArray()
	{
		delete[] mArray;
	}

public:
	T* mArray;
};


/*
���ø� Ư��ȭ : Ư�� �Լ��� (���ϴ� Ÿ�Ը�) ���� ���� ����
*/
template <typename T>
void TemplateSpecialization(T Test)
{
	std::cout << "TemplateSpecialization" << std::endl;
}

template <>
void TemplateSpecialization(int Test)
{
	std::cout << "TemplateSpecialization int" << std::endl;
}


/*
���� ���� ���ø� (Variadic Template) : ���ø��� Ÿ���� ��Ȳ�� ���� ������ ���� �� �� �ִ� ��� (�������� ���ø� ���)
*/
template <typename T>
void VariadicTemplate(T arg)
{
	std::cout << typeid(T).name() << std::endl;
}

template <typename T, typename... Types>
void VariadicTemplate(T arg, Types... args)
{
	std::cout << typeid(T).name() << std::endl;
	VariadicTemplate(args...);
}


int main()
{
	std::cout << Plus<int>(10, 20) << std::endl;
	std::cout << Plus<float>(3.14f, 221.34f) << std::endl;
	// �Ʒ��� ���� Ÿ���� �������� ���� ���, ���ڿ� �� �������� Ÿ������ Ÿ���� ������
	std::cout << Plus(30, 40) << std::endl;

	std::cout << Minus<int>(30, 40) << std::endl;
	std::cout << Minus(3.14f, 12.5f) << std::endl;
	std::cout << Minus(10, 20) << std::endl;

	OutputType<int>();
	OutputType();

	CTemplate<int> t1;
	CTemplate<float> t2;

	t1.mData = 100;
	t2.mData = 3.14f;
	
	t1.Output();
	t2.Output();

	t1.Output2();
	t2.Output2<int>();

	CTemplate1<int, 100> t11;
	CTemplate1<float, 500> t12;
	CTemplate1<float> t13;

	t11.Output();
	t12.Output();
	t13.Output();

	TemplateSpecialization<float>(3.14f);
	TemplateSpecialization<bool>(true);
	TemplateSpecialization(10);

	VariadicTemplate(10, 3.14f, true, "test");

	return 0;
}