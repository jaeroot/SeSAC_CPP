#include <iostream>

/*
함수 오버로딩 : 함수의 이름은 같지만 형태가 다른 것
인자의 개수 혹은 타입이 다를 경우 다른 형태의 함수라고 말할 수 있다.
반환타입도 함수의 형태로 볼 수 있지만, 오버로딩에는 영향을 줄 수 없다.
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

// 반환형은 오버로딩에 영향 x
//int Output(int Number)
//{
//}

/*
함수의 디폴트인자 : 함수에 인자가 있을 경우, 호출 시 반드시 인자에 값을 전달해주어야 했다.
하지만 디폴트 인자는 함수의 인자에 기본값을 설정하여 인자에 값을 전달하면 전달된 값을 사용하고,
전달하지 않을 경우 기본으로 설정된 값을 사용할 수 있게 해주는 기능
인자가 여러개가 있을 경우, 가장 오른쪽 인자부터 디폴트 인자를 사용해야 함
int Num1, int Num2 2개의 인자가 있다면, int Num1 = 100, int Num2 이런식으로 사용이 불가능하다.
*/


int Sum(int Num1, int Num2 = 300)
{
	return Num1 + Num2;
}
int Minus(int Num1, int Num2 = 300)
{
	return Num1 - Num2;
}

// **** default 인자 사용 시, 오버로딩을 주의해야 함 ****
//float Sum(int Num1)
//{
//	return Num1 + 30;
//}

/*
함수 포인터 : 함수의 주소를 담기 위한 변수
코드 영역(메모리)
메모리의 구성 영역 : stack, heap, data, code 영역
함수 실행 시, 코드 영역의 함수 포인터 정보(주소 정보)를 얻어와 해당 위치로 점프해서 실행하게 됨
함수 실행 과정을 따르지 않는 함수 : inline 함수
inline 키워드를 붙이면 컴파일러가 컴파일 할 때, 코드 영역에 해당 코드 내용을 붙여넣어 줌
(ex. inline 함수인 getNum(){return Num}이 있다면 이걸 호출하는 부분에 가져다가 코드화 시켜버림)
스택을 만들거나 메모리 점프가 없어서 빠른 속도로 실행되는 장점이 있으나, 코드가 길면 컴파일 시간을 잡아먹는 단점이 있음


******
****** 함수 호출 규약 ****** << 반드시 알아볼 것
******


일반적으로 스코프 외부에 있는 함수 : 전역 함수
함수의 이름 = 함수의 주소
함수의 호출은 함수주소(인수) 와 같다.

*/

struct FButton
{
	// 클릭과 관련된 변수 생성
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

	// 함수 포인터 선언방법
	// 함수의 형태는 반환타입과 인자에 영향을 받는다.
	// 함수의 이름은 함수의 형태와 관련이 없다.
	// 반환타입 (*포인터명)(인자타입);
	// 위와 같이 함수 포인터 타입의 변수를 선언할 수 있다.
	
	int (*Func)(int, int) = Sum;
	int (*FuncArray[10])(int, int);

	FuncArray[0] = Sum;
	FuncArray[1] = Minus;

	FuncArray[0](10, 20);
	FuncArray[1](10, 20);

	// 함수주소(인수)
	Sum(10, 20);
	std::cout << Func(10, 20) << std::endl;

	Func = Minus;

	std::cout << Func(10, 20) << std::endl;

	// 버튼 입력 시, 클릭하는 기능을 만듦
	// 버튼에 함수 포인터를 하나 갖게 함
	// 창을 종료시키는 기능 실행 시, 함수 포인터를 엮어줌

	// 충돌처리 시, 충돌 감지 기능을 만들고, 함수 포인터를 엮어 다양한 효과를 만들 수 있게 함

	FButton CloseButton, CompileButton;
	CloseButton.ClickFunc = Close;
	CompileButton.ClickFunc = Compile;

	// CloseButton 클릭 시
	CloseButton.ClickFunc();

	// CompileButton 클릭 시
	CompileButton.ClickFunc();

	int a;
	int* b = new int;

	std::cout << &a << std::endl;
	std::cout << b << std::endl;
	delete b;


	return 0;
}