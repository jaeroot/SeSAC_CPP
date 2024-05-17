#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	rand();

	/*
	배열 : 같은 타입의 변수 여러개가 필요할 경우 사용할 수 있는 문법
	주소 : 1바이트 단위로 부여됨, 16진수 16자리로 주소 체계 구성 (16진수 1자리 = 2진수 4자리 = 4bit, 64bit = 16*4)
	비어있는 주소 지정 : 운영체제의 역할
	배열 : 연속된 메모리 공간에 할당됨 (int배열 10개 선언 시, 40byte공간 필요, 40byte만큼 연속된 메모리에 공간을 만들게 됨)

	첫 번째 요소의 주소를 통해 다음 요소의 주소를 알 수 있음

	배열 선언 방법
	변수타입 배열명[개수];
	
	int Array[10];

	배열의 각 요소에 접근하기 위해 인덱스 사용
	인덱스는 0 ~ 개수 - 1 까지 존재
	인덱스는 허용된 범위 내에서만 사용해야 함

	Array[2] = 300;

	*** 배열의 이름은 해당 배열의 시작 메모리 주소이다 ***
	*/

	//int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int Array[10] = { 1,2,3,4 };	// 4번 index부터 모두 0으로 초기화
	int Array[10] = {};	// 모든 요소를 0으로 초기화

	for (int i = 0; i < 10; i++)
	{
		Array[i] = 0;
	}

	Array[2] = 300;
	// Array[20] = 500;

	std::cout << Array[0] << std::endl;
	std::cout << Array[2] << std::endl;
	std::cout << Array << std::endl;


	// 다차원 배열
	int Array1[10][5] = {};	// 50개짜리 1차원 배열이랑 메모리 쓰는건 똑같음
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 줄번호 * 가로개수 + 가로번호
			Array1[i][j] = i * 5 + j;
		}
	}

	int Array2[50] = {};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Array2[i * 5 + j] = i * 5 + j + 1;
		}
	}


	/*
	shuffle
	*/
	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 50;
		int Index2 = rand() % 50;

		// swap
		int Temp = Array2[Index1];
		Array2[Index1] = Array2[Index2];
		Array2[Index2] = Temp;
	}

	// 콘솔창 출력 지움
	system("cls");
	for (auto a : Array2)
	{
		std::cout << a << std::endl;
	}


	return 0;
}