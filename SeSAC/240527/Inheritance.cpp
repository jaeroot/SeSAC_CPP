#include <iostream>

/*
상속 : 클래스 혹은 구조체 사이에 부모와 자식의 관계를 형성할 수 있는 기능
자식 클래스는 부모 클래스의 멤버(변수, 함수)를 물려받아 사용할 수 있게 됨

상속구조에서 생성자는 부모 -> 자식 순서로 호출이 되고
소멸자는 자식 -> 부모 순서로 호출이 됨

protected : 클래스 외부에서는 접근이 불가능하지만, 클래스 내부나 자식 클래스 내부에서는 접근 가능

private : 클래스 외부 혹은 자식 클래스 내부에서는 접근이 불가능하고, 해당 클래스 내부에서는 접근 가능
*/

class CParent
{
public:
	CParent()
	{
		std::cout << "CParent 생성자" << std::endl;
	}

	~CParent()
	{
		std::cout << "CParent 소멸자" << std::endl;
	}

public:
	int mA;

private:
	int mC;

protected:
	int mD;
};

class CParent1
{

public:
	CParent1()
	{
		std::cout << "CParent1 생성자" << std::endl;
	}

	~CParent1()
	{
		std::cout << "CParent1 소멸자" << std::endl;
	}

public:
	int mB;

private:
	int mPrivate;
};

class CChild : public CParent
{

public:
	CChild()
	{
		std::cout << "CChild 생성자" << std::endl;
	}

	~CChild()
	{
		std::cout << "CChild 소멸자" << std::endl;
	}
};

/*
private로 상속을 받았을 때 부모 클래스의 멤버는 외부에서 접근 불가능
단, 현재 클래스에서는 부모의 public, protected 멤버에 접근 가능
*/
class CChild1 : public CParent, private CParent1			// 다중 상속 : 부모 클래스를 여러 개 상속 받는 것
{
public:
	CChild1()
	{
		mB = 10;
		//mPrivate = 100;
		mA = 10;
		//mC = 5;
		mD = 20;
		std::cout << "CChild1 생성자" << std::endl;
	}

	~CChild1()
	{
		std::cout << "CChild1 소멸자" << std::endl;
	}
};

class CChildChild : public CChild
{

public:
	CChildChild()
	{
		std::cout << "CChildChild 생성자" << std::endl;
	}

	~CChildChild()
	{
		std::cout << "CChildChild 소멸자" << std::endl;
	}
};

/*
함수 오버라이딩(함수 재정의) : 클래스나 구조체가 상속관계를 형성하고 있을 때 사용 가능한 문법
꼭 virtual이 아니어도 됨

다형성 : 상속 관계에 있는 클래스가 부모 혹은 자식 타입으로 형변환이 가능한 것
자식 -> 부모 형변환 : 업 캐스팅
부모 -> 자식 형변환 : 다운 캐스팅

캐스팅 4총사
static_cast : 일반적인 형 변환 (int, float)
const_cast : const 해제 가능
reinterpret_cast : 강제 형 변환
dynamic_cast : 상속 관계에서 사용 (다른 type으로 casting 시, nullptr return. 제대로 된 casting이면 주소값 return), 예외처리 가능, 안정적으로 down-casting 가능

가상 함수 있음 : 다형 클래스
가상 함수 없음 : 상속 형식 클래스
dynamic_cast는 다형 클래스만 사용 가능 (가상 함수가 있어야 함)

virtual 키워드를 활용하여 클래스의 멤버 함수나 소멸자를 가상 함수로 만들 수 있음
가상함수는 부모클래스의 가상함수의 자식클래스에 재정의 하면 자식의 함수가 호출될 수 있도록 하는 기능

가상함수를 가지고 있는 클래스 : 부모에 가상함수가 있다면 부모, 자식 클래스 모두 가상함수를 가지고 있는 것과 같음
가상함수를 가지고 있는 클래스는 가상함수 테이블이 생성이 됨
가상함수 테이블은 클래스에 만들어진 가상함수의 메모리 주소를 저장하고 있는 배열임

가상함수를 호출하게 되면 먼저 해당 타입의 가상함수 테이블을 참조하게 됨
casting해서 타입이 바뀌더라도 vtable 정보는 바뀌지 않음
vfptr (virtual function pointer)
가상함수 테이블에 들어가 있는 함수의 주소를 가져와서 호출을 해주기 때문에 가상함수가 자식에 재정의 되었다면 해당 함수가 호출되는 방식

*/

class CEmpty
{
public:
	CEmpty()
	{
		std::cout << "CEmpty 생성자" << std::endl;
	}

	virtual ~CEmpty()
	{
		std::cout << "CEmpty 소멸자" << std::endl;
	}

public:
	virtual void Output()
	{
		std::cout << "CEmpty Output" << std::endl;
	}

	// 순수 가상 함수 : 가상함수 뒤에 =0을 붙여주면 순수 가상함수가 됨
	// 순수 가상 함수는 자식 클래스에 무조건 재정의 해야 함
	// 순수 가상 함수를 가지고 있는 클래스를 추상 클래스라고 함
	// 추상 클래스는 객체 생성이 불가능함
	// 자식 클래스에서 부모의 순수 가상 함수를 재정의 하지 않을 경우, 자식 클래스도 추상 클래스가 됨
	// 순수 가상 함수도 구현부 만들 수 있음
	// abstract 키워드를 통해 순수 가상 함수가 없어도 추상 클래스를 만들 수 있음
	virtual void OutputPure() = 0;

	virtual void OutputPure1() = 0
	{

	}
};

class CEmptyChild : public CEmpty
{
public:
	CEmptyChild()
	{
		std::cout << "CEmptyChild 생성자" << std::endl;
	}

	~CEmptyChild()
	{
		std::cout << "CEmptyChild 소멸자" << std::endl;
	}

public:
	// override 키워드 : 이 함수가 부모에 만들어진 함수를 재정의 하는 함수라고 명시적으로 알려줌
	// 만약 부모에 없는 함수를 만들었다면 error를 발생시킴

	// final 키워드 : 다른 자식 클래스에서 더 이상 재정의 불가
	virtual void Output() override final
	{
		//CEmpty::Output();

		std::cout << "CEmptyChild Output" << std::endl;
	}

	void Output(int test)
	{
		std::cout << "CEmptyChild Output test" << std::endl;
	}

	virtual void OutputPure()
	{

	}

	virtual void OutputPure1()
	{

	}
};

class CEmptyChild1 : public CEmpty
{
public:
	CEmptyChild1()
	{
		std::cout << "CEmptyChild1 생성자" << std::endl;
	}

	~CEmptyChild1()
	{
		std::cout << "CEmptyChild1 소멸자" << std::endl;
	}

	virtual void OutputPure()
	{

	}

	virtual void OutputPure1()
	{

	}
};

class CEmptyChildChild : public CEmptyChild
{
public:
	CEmptyChildChild()
	{
		std::cout << "CEmptyChildChild 생성자" << std::endl;
	}

	~CEmptyChildChild()
	{
		std::cout << "CEmptyChildChild 소멸자" << std::endl;
	}

public:
	//void Output()
	//{
	//	std::cout << ("CEmptyChildChild") << std::endl;
	//}

};

// 클래스 선언 시 클래스 이름 오른쪽에 abstract  키워드를 붙여주면 이 클래스는 추상 클래스가 됨
// 순수 가상 함수가 없어도 추상 클래스로 만들어짐
class CAbstractClass abstract
{

};

// 순수 가상 함수를 가지고 abstract 붙여도 됨
class CAbstractClass1 abstract
{
public:
	virtual void Output() = 0;
};

// 함수에 =0대신 abstract 키워드를 붙여서 순수 가상 함수를 만들 수도 있음
class CAbstractClass2
{
public:
	virtual void Output() abstract;
};

int main()
{
	//CAbstractClass c1;

	// 생성자 소멸자 순서 확인
	//CChild child;
	//CChild1 child1;
	//CChildChild childchild;

	// 다중 상속의 문제
	// 부모 클래스 내 이름이 중복된 경우 모호해질 수 있음
	//CChild1 child1;
	//child1.mA = 50;
	// private으로 상속을 받으면, 부모 클래스에서 public으로 되어 있다 하더라도 외부에서 접근이 되지 않음
	//child1.mB = 100;

	//std::cout << std::endl;
	//std::cout << "CParent : " << sizeof(CParent) << std::endl;
	//std::cout << "CParent1 : " << sizeof(CParent1) << std::endl;
	//std::cout << "CChild : " << sizeof(CChild) << std::endl;
	//std::cout << "CChild1 : " << sizeof(CChild1) << std::endl;
	//std::cout << "CChildChild : " << sizeof(CChildChild) << std::endl;
	//std::cout << "Empty : " << sizeof(CEmpty) << std::endl;
	//std::cout << "CEmptyChild : " << sizeof(CEmptyChild) << std::endl;

	/*std::cout << std::endl;
	CEmpty Empty;
	Empty.Output();

	CEmptyChild EmptyChild;
	EmptyChild.Output();*/
	//CEmptyChild.CEmpty::Output();

	// 업캐스팅
	CEmptyChild child;
	CEmpty* Parent = (CEmpty*)&child;
	CEmptyChild1* DownChild1 = (CEmptyChild1*)Parent;
	CEmptyChild1* DownChildDynamic1 = dynamic_cast<CEmptyChild1*>(Parent);

	CEmpty* ParentArray[10] = {};

	ParentArray[0] = new CEmptyChild;
	ParentArray[1] = new CEmptyChild1;
	ParentArray[2] = new CEmptyChild;

	// 재정의된 함수는 호출하는 객체의 타입에 따라 호출되는 함수가 달라짐
	// 아래는 타입이 CEmpty 타입 포인터를 이용하여 호출하기 때문에 실제 생성된 객체는 Child라 하더라도 CEmpty 클래스의 함수가 호출됨
	ParentArray[0]->Output();
	ParentArray[1]->Output();

	delete ParentArray[0];
	delete ParentArray[1];
	delete ParentArray[2];

	// 가상 함수 있을 때 객체 단위의 memcpy, memset 조심
	// 가상 함수 테이블까지 복사하거나 밀어버릴 수 있음

	// vtable은 객체마다 생성 x
	// 클래스마다 생성돼서 해당 주소를 가지고 있는 것임


	std::cout << std::endl;

	return 0;
}