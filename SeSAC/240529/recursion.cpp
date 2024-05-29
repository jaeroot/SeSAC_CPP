#include <iostream>

/*
재귀함수 : 자기 자신을 호출하는 함수
반복문에 비해 함수 call을 반복하여 stack에 계속 쌓이게 됨
return 할 때마다 추가적인 임시 객체가 계속 생성됨
재귀가 계속 돌다 보면 stack overflow가 발생할 수도 있음
*/
int Factorial(int Number)
{
	if (Number == 1)
		return 1;

	return Number* Factorial(Number - 1);
}

/*
꼬리 재귀 함수
컴파일러가 반복문으로 변형시켜서 동작시킨다? - 디스어셈블 해서 확인해볼것
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