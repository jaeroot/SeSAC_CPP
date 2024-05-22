#include <iostream>

// 전역변수는 데이터 영역에 공간이 만들어지며,
// 프로그램이 시작될때 메모리에 공간이 만들어지고,
// 프로그램이 종료될 때 메모리가 제거된다.
// 전역변수는 이 아래의 모든 곳에서 이 변수를 사용할 수 있다.
// 초기화 값이 없을 경우, 자동으로 0으로 초기화됨
int gNumber = 100;

void StaticTest()
{
	/*
	static : 정적 변수를 만들어 줌
	정적변수 : 데이터 영역에 공간이 만들어짐
	이 함수가 호출될때 메모리에 공간이 만들어지고, 프로그램이 종료될때 메모리에서 제거됨
	static을 붙여서 정적변수를 만들 수 있다.
	초기화는 처음 딱 1번만 되고, 초기화시 값을 지정하지 않을 경우 자동으로 0으로 초기화됨
	*/
	int Number = 100;
	++Number;
	std::cout << "Number = " << Number << std::endl;

	static int NumberStatic = 100;
	++NumberStatic;
	std::cout << "NumberStatic = " << NumberStatic << std::endl;
}

int main()
{
	/*
	레퍼런스 : 다른 변수를 참조하여 참조하는 변수의 값을 변경하거나 가져와서 사용할 수 있게 해주는 기능
	레퍼런스는 반드시 선언과 동시에 참조할 대상을 지정해야 함
	처음 한번 참조하면 그 뒤부터 참조하는 대상을 변경할 수 없다.
	*/
	int Number = 100;
	int Number1 = 200;

	int* Pointer = &Number;
	Pointer = &Number1;

	//int& Ref;
	//Ref = Number;
	int& Ref = Number;
	// 위에서 Ref는 Number를 참조
	// 아래 코드는 Number1를 참조하는 것이 아니라, Number1에 있는 값을 참조하는 대상인 Number에 대입하는 것이다
	Ref = Number1;

	// 레퍼런스도 const를 왼쪽에 붙여주면 참조하는 대상의 값을 변경할 수 없다
	const int& CosntRef = Number;
	//ConstRef = 300;
	
	StaticTest();
	StaticTest();
	StaticTest();
	StaticTest();


	// 스택 : 지역변수
	// 데이터 : 정적변수, 전역변수
	// 힙 : 동적할당
	// 코드 : 코드가 저장되는 공간

	/*
	동적할당 : new를 이용해서 동적으로 메모리공간을 만들 수 있다 (new 연산자)
	동적할당된 메모리는 반드시 delete 키워드를 이용해서 제거해야 함
	하지 않으면 메모리 누수(memory leak) 발생

	new 변수타입;
	변수타입 크기 만큼 힙 영역에 공간을 만들고, 그 메모리 주소를 반환해줌
	*/
	int* DynamicInt = new int;
	delete DynamicInt;
	// new랑 delete는 속도가 느림. 메모리 풀을 사용하기도 함
	// 동적할당은 메모리가 붙어서 나온다는 보장이 없음.
	// 메모리 단편화가 발생하기도 함 - 해결하기 위해 메모리풀, 페이징 등 이용

	int* DynamicArray = new int[10];
	delete[] DynamicArray;

	return 0;
}