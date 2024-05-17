#include <iostream>
#include <time.h>

int main()
{
	// 난수 :	랜덤한 수
	// rand();	난수 생성
	srand(time(NULL));
	rand();		// 값 범위 최대 만단위, 소숫점 둘째자리 정도까지밖에 안됨. 정밀한게 안됨, rand두번 쓰거나 해야함
	std::cout << rand() << std::endl;

	// 0 ~ 100 사이의 랜덤한 수를 출력
	std::cout << rand() % 101 << std::endl;

	// 100 ~ 200 사이의 랜덤한 수를 출력
	std::cout << rand() % 101 + 100 << std::endl;

	// 최소공격력 ~ 최대공격력 사이의 랜덤한 공격력 출력
	int AttackMin = 100;
	int AttackMax = 300;
	int Attack = rand() % (AttackMax - AttackMin + 1) + AttackMin;
	std::cout << "공격력 : " << Attack << std::endl;

	// 0 ~ 100 사이의 값을 소수점 2번째 자리까지 구해야 함
	float Percent = rand() % 10001 / 100.0f;
	std::cout << Percent << std::endl;

	if (Percent <= 0.01f)
	{
		std::cout << "성공" << std::endl;
	}
	else
	{
		std::cout << "실패" << std::endl;
	}

	/*
	반복문 : 같은 코드를 여러번 반복해서 동작시켜줄 때 사용
	for, while, do while

	for (초기값; 조건식; 증감값)
	{
		반복할때 동작할 코드
	}
	초기값 : for문이 시작될 때 1번만 동작
	조건식, 증감값 : for문이 동작되는 동안 계속 동작

	조건식이 true이면 코드가 동작, false이면 for문 종료

	초기값 -> 조건식(true) -> 코드 -> 증감값 -> 조건식 -> ... -> 조건식(false) -> for문 종료
	초기값에서는 변수를 선언할 수 있음
	초기값에서 선언된 변수는 for문 내부에서만 사용 가능
	*/

	for (int i = 0; i < 10000; i++)
	{
		Percent = rand() % 10001 / 100.0f;

		std::cout << i << " : " << Percent << std::endl;
		if (Percent <= 0.01f)
		{
			break;
		}
	}

	// 중첩 for문
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				// 총 150번 반복
			}
		}
	}


	// while문
	// while (조건식)
	// {
	//		반복할 코드
	// }
	// 조건식이 false가 되거나 break를 만나면 while문을 빠져나감

	int Number = 0;
	while (Number < 10)
	{
		++Number;
	}

	// do while문
	// do
	// {
	//		동작할 코드
	// } while(조건식);
	// 코드를 한 번 실행한 후 while문 조건 체크, true면 반복, false면 while문 종료

	return 0;
}