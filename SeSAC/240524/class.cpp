#include <iostream>

/*
절차지향 프로그래밍 : 순서에 의존적임

객체 : 프로그래밍에서는 생성된 인스턴스를 말함 (구조체, 클래스 등으로부터 생성한 변수(인스턴스))
객체지향 프로그래밍(OOP) : 객체들을 조립하여 프로그램을 만들어 나가는 기법

클래스 : 객체를 생성하기 위해 C++에서 지원하는 문법 중 하나
클래스는 여러 멤버 변수와 여러 멤버 함수를 가질 수 있음
구조체도 상속은 가능함. C++에선 구조체와 클래스가 거의 동일함

class 클래스명
{
	멤버변수 및 멤버함수
};

클래스 멤버 접근 지정
클래스 내부 : 클래스의 멤버함수 안을 의미

클래스 외부 : 클래스의 멤버함수를 제외한 다른곳을 의미

public : 클래스 내부와 외부에서 모두 접근이 가능

private : 클래스 내부에서는 접근이 가능하지만, 외부에서는 불가능

protected : 

클래스는 접근지정이 없을 경우, 기본으로 private으로 설정
구조체는 접근지정이 없을 경우, 기본으로 public으로 설정


클래스의 생성자와 소멸자
생성자 : 클래스를 이용해서 객체가 생성될 때 자동으로 호출되는 함수
소멸자 : 클래스를 이용해서 생성한 객체가 메모리에서 제거될 때 자동으로 호출되는 함수

생성자와 소멸자의 함수 이름은 클래스의 이름과 동일하게 작성
CPlayer() 생성자
~CPlayer() 소멸자

클래스는 생성자와 소멸자가 없을 경우, 자동으로 기본 생성자와 소멸자가 처리됨
*/

class CPlayer
{
	// 은닉화
	// 멤버변수 및 멤버함수에 접근 지정자를 붙일 수 있음
	// 클래스의 멤버 변수는 대부분 외부에 공개를 하지 않고 private를 많이 씀
	// 필요하면 getter나 setter를 쓰는 방식으로 (set함수, get함수를 접근자 라고 많이 함)
	// 이렇게 제한하는 장점 : 변경되는 부분을 한정지을 수 있음. 또한 디버깅 시 유리 (찾을 부분 줄어듦)
	// 소멸자와 달리 생성자는 다양한 형태가 나올 수 있음
	
public:
	CPlayer()
		// int Defense = 0; 과 같다.
		// 생성 전 초기화
		: mDefense(0)
	{
		mArray = new int[10];
		memset(mArray, 0, sizeof(int) * 10);

		// int mAttack; mAttack = 0; 과 같다
		// 생성 후 초기화
		mAttack = 0;
		std::cout << "CPlayer 생성자" << std::endl;
	}

	// 생성자 오버로딩
	CPlayer(const char* Name)
	//	: mName(Name)		// 문자열은 initializer가 안됨
	{
		mArray = new int[10];
		memset(mArray, 0, sizeof(int) * 10);

		// 문자열은 복사를 해 주어야 함
		strcpy_s(mName, Name);
		
		std::cout << "이름만 있는 생성자" << std::endl;
	}

	CPlayer(const char* Name, int Attack, int Defense)
		: mAttack(Attack), mDefense(Defense)
	{
		mArray = new int[10];

		// 1번 인자에 들어가는 주소에 2번 인자에 들어가는 값으로, 3번 인자에 들어가는 크기만큼 채워줌
		// 단, 이 값은 1 바이트 단위로 채워짐
		// 반복문보다 memset이 더 빠름
		memset(mArray, 0, sizeof(int) * 10);

		strcpy_s(mName, Name);

		std::cout << "이름, 공격력, 방어력이 있는 생성자" << std::endl;
	}

	/*
	복사 생성자 : 새로 생성하는 객체에 같은 클래스 타입의 다른 객체를 전달해주어서 전달받은 객체의 내용을 그대로 복사한 객체를 만들어낼 때 사용
	const 클래스& 타입의 인자를 받게 됨

	얕은 복사 (shallow copy) : 인자로 전달받은 객체의 데이터를 모두 그대로 복사하는 방식
	하지만 얕은 복사는 동적 할당과 같은 상황일 때 문제가 생김

	깊은 복사 (deep copy) : 인자로 전달받은 객체의 일반 데이터들은 모두 그대로 복사하고,
	만약 동적할당된 공간이 있다면 새롭게 공간을 생성하고 전달받은 객체에 있는 메모리 주소를 이용해서 값만 얻어와서 복사하는 방식
	
	*/

	CPlayer(const CPlayer& ref)
	{
		//mArray = ref.mArray;		// 얕은 복사, delete했을 때 crash

		mArray = new int[10];

		// 메모리 고속 copy, 속도가 굉장히 빠름. 1번 인자에 들어가는 주소에 2번에 들어가는 주소로부터 3번 인자에 들어가는 바이트 수 만큼 메모리 복사
		memcpy(mArray, ref.mArray, sizeof(int) * 10);	

		mAttack = ref.mAttack;
		mDefense = ref.mDefense;
		mHP = ref.mHP;
		mHPMax = ref.mHPMax;
		strcpy_s(mName, ref.mName);
	}

	/*
	이동 생성자
	새로운 오브젝트에 소유권을 바꿔 주는 것 (소유권 이전)
	객체를 대입하거나 return할 때 임시 객체가 생성이 됨
	&& 타입의 인자를 받게 됨
	*/
	CPlayer(CPlayer&& other)
	{
		mAttack = other.mAttack;
	}


	~CPlayer()
	{
		delete[] mArray;
		std::cout << "CPlayer 소멸자" << std::endl;
	}


public:
	void SetAttack(int Attack)
	{
		mAttack = Attack;
	}

	void SetHP(int HP)
	{
		mHP = HP;
	}

	void AddHP(int HP)
	{
		mHP += HP;
	}

public:
	int GetAttack()
	{
		return mAttack;
	}

	void Output()
	{
		//std::cout << "공격력 : " << this->mAttack << std::endl;
		std::cout << "공격력 : " << mAttack << std::endl;	// 클래스의 멤버 변수는 this-> 를 생략할 수 있음
	}

	CPlayer SetTest(CPlayer player)
	{
		return player;
	}

private:
	// 선언하면서 초기화
	char mName[32] = {};
	int mAttack;
	int mDefense;
	int mHP = 0;
	int mHPMax;
	int* mArray;
};

class CEmpty
{

};

int main()
{
	// 클래스 상속이 들어갈 경우 빈 클래스가 1이 아닐 수 있음
	// 하지만 기본적인 빈 클래스는 크기가 1바이트임 (구조체도 마찬가지)
	// 멤버 함수는 클래스의 크기에 영향을 주지 않음
	std::cout << sizeof(CEmpty) << std::endl;

	CPlayer player;
	CPlayer player1("입력한 이름");
	CPlayer player2("이름", 10, 20);
	CPlayer* player3 = new CPlayer("이름", 30, 40);
	CPlayer player4(player2);

	// class끼리 대입 가능
	// 클래스끼리의 대입은 오른쪽 객체의 멤버 변수 값을 왼쪽 객체의 멤버 변수에 복사하는것임
	//player4 = player1;		// 얕은 복사, 대입함수 호출 operator

	// 선언과 동시에 대입을 해도 복사 생성자가 됨. 하지만 단순 대입은 복사 생성자 x
	CPlayer player5 = player1;	// 복사 생성자

	//player5.SetTest(CPlayer());
	

	/*
	클래스 멤버 함수의 주소는 1개 뿐임
	멤버 함수에서 호출하는 객체의 멤버변수를 정확하게 사용할 수 있는 이유는 this 때문
	this는 자기자신의 포인터
	아래와 같이 호출을 하게 되면 CPlayer 클래스의 Output 함수를 호출할 때 player4 객체의 메모리 주소를 this에 넣어서 호출한다는 의미
	즉, 클래스의 멤버 함수를 호출하기 위해서 반드시 this에 넣어줄 객체를 이용하여 호출을 해야 함
	*/
	player.Output();
	player1.Output();
	player4.Output();
	//CPlayer playerArray[10] = {};
	//CPlayer* PlayerDynamic = new CPlayer;		
	// PlayerDynamic은 메모리 주소를 담기 위한 포인터 변수일 뿐 객체가 아님
	// new CPlayer를 통해 힙에 동적할당 된 객체가 return한 주소값을 들고 있는 포인터 변수임

	//PlayerDynamic->SetHP(300);

	//player.mAttack = 10;
	//player.mDefense = 100;		// private라 접근 불가능
	player.SetHP(500);
	player.SetAttack(50);

	std::cout << player.GetAttack() << std::endl;
	player.Output();
	
	delete player3;
	//delete PlayerDynamic;

	return 0;
}