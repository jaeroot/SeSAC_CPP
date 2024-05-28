#include <iostream>
#include <assert.h>

/*
operator : 연산자 재정의
클래스나 구조체에도 사용할 수 있고 일반 연산자도 변경 가능



*/

struct FVector
{
	float x;
	float y;
	float z;

	// static 멤버 변수
	// 클래스나 구조체에 static 멤버 변수를 사용할 경우, 이 변수는 반드시 전역적(클래스 외부)으로 선언이 되어야 하고,
	// 이 멤버 변수는 이 클래스나 구조체를 이용하여 생성한 모든 객체가 공유하며 사용되는 공간이 만들어짐
	// 단, 쓰레드일 경우 문제가 생길 수 있음
	// thread-unsafe 하기에 동기화 처리 해주면 됨
	static FVector result1;

public:
	FVector()
	{

	}

	FVector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	FVector(const FVector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

public:
	// 아래와 같은 식은 stack에 지역변수를 할당하기에 댕글링 포인터 문제가 생길 수 있음. 주의할 것
	//FVector* aa()
	//{
	//	FVector a;

	//	return &a;
	//}

	// 멤버 함수나 operator 뒤에 const가 붙어있으면 이 함수나 operator에서는 멤버변수의 값을 변경할 수 없다
	const FVector& operator + (const FVector& v) const
	{
		FVector result;

		result1.x = x + v.x;
		result1.y = y + v.y;
		result1.z = z + v.z;

		return result1;
	}

	// operator도 함수이기에 오버로딩 가능
	const FVector& operator + (float Value) const
	{
		// static FVector result;
		// static은 함수마다 생성되는 문제가 있을 수 있음
		FVector result;

		result1.x = x + Value;
		result1.y = y + Value;
		result1.z = z + Value;

		return result1;
	}

	void operator += (const FVector& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

public:
	FVector& operator = (const FVector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	FVector& operator = (float Value)
	{
		x = Value;
		y = Value;
		z = Value;

		return *this;
	}

	float operator [] (int Index) const
	{
		if (Index == 0)
			return x;

		else if (Index == 1)
			return y;

		else if (Index == 2)
			return z;

		// assert 첫 인자 : 0 - false로 에러가 나옴, 그 외 값 - true로 에러가 안나옴
		assert(false);

		return FLT_MAX;
	}

public:
	void Output()
	{
		printf("x = %.5f, y = %.5f, z = %.5f\n", x, y, z);
	}

	// static 멤버 함수는 this가 없다
	// 그렇기 때문에 일반 멤버변수를 사용할 수 없다
	// static 멤버 변수는 사용이 가능
	// static 멤버 함수는 전역 함수처럼 인식
	static void OutputStatic()
	{
		//printf("x = %.5f, y = %.5f, z = %.5f", x, y, z);
		printf("OutputStatic FUnction\n");
	}
};

//FVector operator+(const FVector& v1, const FVector& v2)
//{
//	return FVector{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
//}

// data영역에 만들어지고 전역 변수와 같음.. main 실행 종료 시에 메모리에서 제거됨
FVector FVector::result1 = {};

int main()
{
	FVector v1, v2, v3;
	v1.x = 1.0f;
	v1.y = 2.0f;
	v1.z = 3.0f;

	v2.x = 4.0f;
	v2.y = 5.0f;
	v2.z = 6.0f;

	// v1의 + 오퍼레이터 호출
	// 인자로 v2를 넘겨 줌
	v3 = v1 + v2;

	// const 객체는 일반 멤버 함수를 호출할 수 없음
	// 멤버 함수 뒤에 const가 붙은 함수만 호출 가능
	// operator 재정의 함수 뒤에 const를 붙여 줘야 함
	const FVector v4 = { 7.0f, 8.0f, 9.0f };
	v3 = v4 + v1;
	v3 = v4 + 100.0f;

	std::cout << v3[1] << std::endl;
	//std::cout << v3[5] << std::endl;

	// static 변수의 메모리 크기는 객체의 메모리 크기에 영향을 주지 않음
	std::cout << sizeof(FVector) << std::endl;

	// 메모리 공간을 공유함
	std::cout << &v1.result1 << std::endl;
	std::cout << &v2.result1 << std::endl;

	v3.Output();

	v3.OutputStatic();
	v3.result1;

	FVector::result1;
	FVector::OutputStatic();
	
	// 전역 함수는 & 붙이던 안붙이던 같음
	// 멤버 함수는 & 붙여야 함
	std::cout << FVector::OutputStatic << std::endl;
	std::cout << &FVector::OutputStatic << std::endl;
	//std::cout << FVector::Output << std::endl;		// error

	void (*Func)() = FVector::OutputStatic;
	Func();
	
	void (FVector:: * Func1)() = &FVector::Output;
	
	// 일반 멤버함수는 this에 전달해줄 객체의 주소가 필요함
	// 그러므로 객체를 이용하여 호출해주어야 함
	//Func1();
	(v3.*Func1)();
	(v1.*Func1)();

	// singleton - static 활용 (관리자 클래스 같은거 만들 때 많이 씀, 몬스터 관리자, 아이템 관리자)

	return 0;
}