#include <iostream>

namespace EJob2
{
	enum Type : unsigned short
	{
		None,
		Knight = 100,
		Archer,
		Magicion
	};
}

int main()
{
	/*
	if문 : 특정 조건을 지정하고 조건이 true일 경우 동작하는 문법

	형태
	if (조건식)
	{
		동작할 코드
	}

	if (조건식)
		동작할 코드

	동작할 코드가 1줄일 경우 코드블록(중괄호)를 생략할 수 있음

	else와 else if를 함께 사용하면 분기처리를 할 수 있음

	else와 else if는 독립적으로 사용이 불가능함, 반드시 if 아래에 와야 함
	else는 조건 필요 없이 위의 if 문이나 else if 문의 조건이 false일 경우 무조건 동작함
	else는 if문 1개에 최대 1개만 들어가야 함

	else if는 if문 1개에 여러개가 들어갈 수 있음
	위의 if나 else if의 조건식이 false일 경우, 현재 else if의 조건식을 체크하는 방식

	삼항연산자 : 조건을 체크하여 true일 때와 false일때 구해줄 값을 지정할 수 있음
	조건식 ? true일때 값 : false일때 값;
	*/


	/*
	switch문 : 분기처리를 진행함
	괄호 안에 들어가는 값이 몇인지를 체크하는 문법

	switch (변수)
	{
	case 상수:
		break;
	case 상수:
		break;
	default:
		break;
	}

	case안에서 변수 선언 및 초기화를 하려면 코드 블럭(중괄호, {})로 묶고 사용해야 함
	case 1:
	{
		int Number = 3;
	}
	break;

	case의 조건은 숫자를 쓰는것보단 const로 상수화를 한 변수를 넣는 것이 가독성이 더 좋음 (혹은 열거형)
	*/


	/*
	열거형 : 상수에 이름을 부여해주는 기능
	열거형의 요소들은 0부터 시작하여 값이 1씩 증가하게 됨

	enum 열거형이름
	{
		요소1,
		요소2,
		요소3
	};

	enum 열거형이름
	{
		요소1,			// 0
		요소2 = 100,		// 100
		요소3,			// 101
		요소4			// 102
	};

	열거형은 일종의 사용자정의 타입이 됨
	사용자 정의 타입 : 우리가 원하는 변수 타입을 만드는 것
	열거형의 이름은 변수 타입이 됨
	열거형의 요소는 상수, 기본적으로 4byte로 잡힘 (int로 인식, 원하면 다른 타입으로 변경할 수 있음)
	*/
	enum EJob
	{
		None,
		Knight = 100,
		Archer,
		Magicion
	};

	int Job = Knight;
	EJob Job1 = Knight;
	// Job1 = 20;		int에 열거형의 요소 대입은 가능하나, 열거형 타입의 변수에는 int 타입 대입이 불가능함
	Job1 = (EJob)3;		// 형 변환 해서는 가능


	/*
	namespace EJob
	{
		enum EJob
		{
			None,
			Knight = 100,
			Archer,
			Magicion
		};
	}
	EJob::Knight;
	EJob::Type = 
	*/

	enum class EJob1 : char
	{
		None,
		Knight,
		Archer,
		Magicion
	};

	std::cout << sizeof(EJob2::Type) << std::endl;
	std::cout << sizeof(EJob1) << std::endl;

	// 일반 열거형은 int 타입에 대입이 됨
	// enum class는 안됨, 컴파일 단계에서 타입을 꼼꼼히 따짐
	// enum class는 같은 타입인지 엄격하게 따짐, 물론 작정하고 형변환 하면 되긴 함....
	// int에 값을 넣고 사용할때는 일반 열거형이 편함

	// switch 쓰고 탭, 괄호에 enum class 열거형 타입을 적음, tab 후 엔터 하면 자동완성 해줌, namespace 안에 있는 애는 안해줌
	/*
	switch (EJob1)
	{
	case EJob1::None:
		break;
	case EJob1::Knight:
		break;
	case EJob1::Archer:
		break;
	case EJob1::Magicion:
		break;
	default:
		break;
	}
	*/


	return 0;
}