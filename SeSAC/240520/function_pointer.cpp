#include <iostream>

/*
함수 : 특정 동작을 하는 코드를 미리 작성하고, 필요할 때 호출하여 사용할 수 있는 기능을 제공하는 것

반환타입 함수명(인자)
{
}

함수는 구현되어 있는 기능을 동작시키고 함수의 결과를 반환 할 수 있음
반환타입 : 함수의 결과를 반환해야 할 변수 타입을 지정
반환이 없음 : void
반환이 있음 : void 외의 타입
return 키워드를 이용해서 함수의 결과를 반환할 수 있다.

void는 타입이 없다는 의미
함수의 반환 타입을 void로 하면 결과를 반환하지 않아도 된다.

함수명 : 함수 이름 작성

인자 : 함수가 동작할 때 필요한 데이터를 넘겨줄 목적으로 사용
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
함수 내부에 선언된 변수를 지역변수라고 한다.
지역변수는 해당 함수 내에서만 사용이 가능하고, 함수 외부에서는 사용이 불가능함
지역변수는 메모리 영역 중에 스택이라는 영역에 공간이 만들어짐
지역변수는 함수가 종료되면 메모리에서 제거됨
*/
void ChangeNumber(int Number)
{
	Number = 999;
}

// 전역변수는 data영역에 공간이 만들어짐
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
	포인터 : 메모리 주소를 저장하는 변수
	모든 변수 타입은 포인터 타입 변수를 선언할 수 있음
	int변수의 주소는 int의 포인터 타입 변수에 저장해야 한다

	변수타입* 포인터명; 으로 선언할 수 있음
	*/
	int* Pointer = nullptr;

	// 변수 앞에 &를 붙여주면 해당 변수의 메모리 주소를 의미함
	Pointer = &Number;

	// 역참조를 통해 가지고 있는 메모리 주소에 접근하여 값을 변경하거나 얻어와서 사용할 수 있음
	*Pointer = 999;
	std::cout << Number << std::endl;

	ChangeNumber1(&Number);
	std::cout << Number << std::endl;

	int Array[10] = {};
	std::cout << Array << std::endl;
	
	// 배열 시작 주소[인덱스]
	Array[1] = 100;

	int* PointerArray = Array;
	PointerArray[3] = 200;

	SetArray(Array);

	for (int i = 0; i < 10; i++)
	{
		std::cout << Array[i] << std::endl;
	}

	// 포인터 연산 : +, -가 가능함
	// 포인터의 연산은 타입에 영향을 받음
	// int 포인터의 경우 3을 더하면 단순히 주소가 3만큼 증가하는 것이 아닌, 3 * int의 크기 만큼 주소가 증가하게 됨
	// index로 접근하는 것을 random access라고 함 (결국 포인터 주소 연산임)

	std::cout << PointerArray << std::endl;
	std::cout << PointerArray + 1 << std::endl;
	PointerArray[2] = 300;
	*(PointerArray + 2) = 111;
	std::cout << Array[2] << std::endl;


	return 0;
}