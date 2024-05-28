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
	// pointer���� �ϴ� ���� : static�̱⿡ ���� �� ���� �׻� �޸𸮿� ���� �ְ� ��
	// ���� �Ҵ� �ϸ� �߰��� ���� �� �� ����
	// ��, �޸� ��Ʈ���� ������ (8byte �� ������ ��ü ��ü ���󺸴� ����� ��)
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
	// �����ڰ� private�̱⿡ main���� ȣ���� ���� ����
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