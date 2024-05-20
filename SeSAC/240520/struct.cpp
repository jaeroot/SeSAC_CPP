#include <iostream>

int main()
{
	/*
	구조체 : 여러 타입의 변수들을 하나로 묶어서 사용할 수 있게 해주는 기능

	struct 구조체명
	{
		변수들
	};


	*/

	enum Type : unsigned char // 1바이트로 만들어짐
	{
		Knight,
		Archer,
		Magicion
	};

	struct FItem
	{
		char Name[32] = "";
		int Option;
	};

	struct FPlayer
	{
		char Name[32] = "";
		Type Job = Knight;
		int Attack = 0;
		int Defense = 0;
		__int64 HP = 0;
		FItem Item;

		// 구조체 멤버 맞춤
		// 프로젝트 - 속성 - C/C++ - 코드맞춤
		// 멤버 맞춤은 제일 큰 자료형 기준으로 맞춰버림
		// 서버에선 보통 바이트단위로 하는 경우가 많음
		// 클라 - 서버 간의 통신을 할 때는 크기를 통일시켜서 작업해야 함
	};

	//FPlayer Player = {};	// 배열처럼 전부 0으로 초기화
	FPlayer Player = { "기사", Knight, 100 };	// defense는 0, 나머지는 넣어준 값으로 초기화
	// 구조체 안의 변수들을 선언과 동시에 초기화 할 수 있음

	// 구조체의 크기는 구조체를 이루고 있는 멤버 변수들의 총합과 같음
	FPlayer PlayerArray[10];

	Player.Job = Knight;
	Player.Item.Option = 30;
	std::cout << Player.Attack << std::endl;
	std::cout << sizeof(Type) << std::endl;
	std::cout << sizeof(FPlayer) << std::endl;

	return 0;
}