#include <iostream>

class CSingleton
{
private:
	CSingleton()
	{

	}

	~CSingleton()
	{
	}

private:
	// pointer여야 하는 이유 : static이기에 종료 시 까지 항상 메모리에 남아 있게 됨
	// 동적 할당 하면 중간에 삭제 할 수 있음
	// 즉, 메모리 컨트롤이 가능함 (8byte 더 쓰지만 객체 자체 생상보단 비용이 쌈)
	static CSingleton* mInst;

public:
	static CSingleton* GetInstance()
	{
		if (nullptr == mInst)
			mInst = new CSingleton;

		return mInst;
	}

	static void DestroyInstance()
	{
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}
};

CSingleton* CSingleton::mInst = nullptr;

int main()
{
	// 생성자가 private이기에 main에서 호출이 되지 않음
	//CSingleton single;
	std::cout << CSingleton::GetInstance() << std::endl;
	std::cout << CSingleton::GetInstance() << std::endl;
	std::cout << CSingleton::GetInstance() << std::endl;
	std::cout << CSingleton::GetInstance() << std::endl;

	CSingleton::DestroyInstance();


	CSingleton::GetInstance();
	CSingleton::DestroyInstance();

	return 0;
}