#include <iostream>



int main()
{
	//const가 붙으면 상수가 됨
	int Number = 100;
	int Number1 = 300;

	// 포인터 변수 선언 시, 변수타입 왼쪽에 const가 붙을 경우 
	// 참조하는 대상의 값을 변경할 수 없음
	// 참조하는 대상 변경은 가능
	const int* Pointer = &Number;
	//*Pointer = 200;			// error
	Pointer = &Number1;


	// 포인터 변수 선언 시, 변수타입 오른쪽에 const가 붙을 경우
	// 참조하는 대상의 값을 변경할 수 있음
	// 참조하는 대상 변경은 불가능
	int* const Pointer2 = &Number;
	*Pointer2 = 500;
	//Pointer2 = &Number1;		// error


	// 두 종류의 포인터 특성을 모두 가짐. 값만 가져다 사용 가능
	// 포인터 변수 선언 시, 변수타입 왼쪽과 오른쪽에 const가 붙을 경우
	// 참조하는 대상의 값을 변경할 수 없음
	// 참조하는 대상 변경도 불가능
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