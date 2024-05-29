#include <iostream>

/*
template : 클래스, 구조체, 함수에서 사용 가능
원하는 부분에서 타입을 원하는 타입으로 지정할 수 있는 기능
template <typename 원하는이름, typename 원하는이름>
typename대신 class를 써도 됨
template <class 원하는이름, typename 원하는이름>
*/

template <typename T>
T Plus(T Num1, T Num2)
{
	//if (typeid(T).hash_code() == typeid(float).hash_code())

	return Num1 + Num2;
}

// 템플릿은 기본타입을 지정할 수 있음 (함수 default 인자처럼 오른쪽부터)
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
비타입 템플릿 인자 : 가변 타입이 아닌 고정된 타입을 지정함
아래와 같이 선언하면 Count는 상수가 됨
#define Count 500, #define Count 100과 다른 점 : define은 이름이 중복돼서 선언이 안 됨
이렇게 쓰면 객체마다 같은 Count라는 상수 이름으로 다른 값을 쓸 수 있음
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
템플릿 특수화 : 특정 함수만 (원하는 타입만) 따로 빼서 구현
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
가변 인자 템플릿 (Variadic Template) : 템플릿의 타입을 상황에 맞춰 개수를 조절 할 수 있는 기능 (가변길이 템플릿 기능)
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
	// 아래와 같이 타입을 지정하지 않을 경우, 인자에 들어간 데이터의 타입으로 타입이 결정됨
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