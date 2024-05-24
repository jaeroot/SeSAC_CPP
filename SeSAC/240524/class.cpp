#include <iostream>

/*
�������� ���α׷��� : ������ ��������

��ü : ���α׷��ֿ����� ������ �ν��Ͻ��� ���� (����ü, Ŭ���� �����κ��� ������ ����(�ν��Ͻ�))
��ü���� ���α׷���(OOP) : ��ü���� �����Ͽ� ���α׷��� ����� ������ ���

Ŭ���� : ��ü�� �����ϱ� ���� C++���� �����ϴ� ���� �� �ϳ�
Ŭ������ ���� ��� ������ ���� ��� �Լ��� ���� �� ����
����ü�� ����� ������. C++���� ����ü�� Ŭ������ ���� ������

class Ŭ������
{
	������� �� ����Լ�
};

Ŭ���� ��� ���� ����
Ŭ���� ���� : Ŭ������ ����Լ� ���� �ǹ�

Ŭ���� �ܺ� : Ŭ������ ����Լ��� ������ �ٸ����� �ǹ�

public : Ŭ���� ���ο� �ܺο��� ��� ������ ����

private : Ŭ���� ���ο����� ������ ����������, �ܺο����� �Ұ���

protected : 

Ŭ������ ���������� ���� ���, �⺻���� private���� ����
����ü�� ���������� ���� ���, �⺻���� public���� ����


Ŭ������ �����ڿ� �Ҹ���
������ : Ŭ������ �̿��ؼ� ��ü�� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
�Ҹ��� : Ŭ������ �̿��ؼ� ������ ��ü�� �޸𸮿��� ���ŵ� �� �ڵ����� ȣ��Ǵ� �Լ�

�����ڿ� �Ҹ����� �Լ� �̸��� Ŭ������ �̸��� �����ϰ� �ۼ�
CPlayer() ������
~CPlayer() �Ҹ���

Ŭ������ �����ڿ� �Ҹ��ڰ� ���� ���, �ڵ����� �⺻ �����ڿ� �Ҹ��ڰ� ó����
*/

class CPlayer
{
	// ����ȭ
	// ������� �� ����Լ��� ���� �����ڸ� ���� �� ����
	// Ŭ������ ��� ������ ��κ� �ܺο� ������ ���� �ʰ� private�� ���� ��
	// �ʿ��ϸ� getter�� setter�� ���� ������� (set�Լ�, get�Լ��� ������ ��� ���� ��)
	// �̷��� �����ϴ� ���� : ����Ǵ� �κ��� �������� �� ����. ���� ����� �� ���� (ã�� �κ� �پ��)
	// �Ҹ��ڿ� �޸� �����ڴ� �پ��� ���°� ���� �� ����
	
public:
	CPlayer()
		// int Defense = 0; �� ����.
		// ���� �� �ʱ�ȭ
		: mDefense(0)
	{
		mArray = new int[10];
		memset(mArray, 0, sizeof(int) * 10);

		// int mAttack; mAttack = 0; �� ����
		// ���� �� �ʱ�ȭ
		mAttack = 0;
		std::cout << "CPlayer ������" << std::endl;
	}

	// ������ �����ε�
	CPlayer(const char* Name)
	//	: mName(Name)		// ���ڿ��� initializer�� �ȵ�
	{
		mArray = new int[10];
		memset(mArray, 0, sizeof(int) * 10);

		// ���ڿ��� ���縦 �� �־�� ��
		strcpy_s(mName, Name);
		
		std::cout << "�̸��� �ִ� ������" << std::endl;
	}

	CPlayer(const char* Name, int Attack, int Defense)
		: mAttack(Attack), mDefense(Defense)
	{
		mArray = new int[10];

		// 1�� ���ڿ� ���� �ּҿ� 2�� ���ڿ� ���� ������, 3�� ���ڿ� ���� ũ�⸸ŭ ä����
		// ��, �� ���� 1 ����Ʈ ������ ä����
		// �ݺ������� memset�� �� ����
		memset(mArray, 0, sizeof(int) * 10);

		strcpy_s(mName, Name);

		std::cout << "�̸�, ���ݷ�, ������ �ִ� ������" << std::endl;
	}

	/*
	���� ������ : ���� �����ϴ� ��ü�� ���� Ŭ���� Ÿ���� �ٸ� ��ü�� �������־ ���޹��� ��ü�� ������ �״�� ������ ��ü�� ���� �� ���
	const Ŭ����& Ÿ���� ���ڸ� �ް� ��

	���� ���� (shallow copy) : ���ڷ� ���޹��� ��ü�� �����͸� ��� �״�� �����ϴ� ���
	������ ���� ����� ���� �Ҵ�� ���� ��Ȳ�� �� ������ ����

	���� ���� (deep copy) : ���ڷ� ���޹��� ��ü�� �Ϲ� �����͵��� ��� �״�� �����ϰ�,
	���� �����Ҵ�� ������ �ִٸ� ���Ӱ� ������ �����ϰ� ���޹��� ��ü�� �ִ� �޸� �ּҸ� �̿��ؼ� ���� ���ͼ� �����ϴ� ���
	
	*/

	CPlayer(const CPlayer& ref)
	{
		//mArray = ref.mArray;		// ���� ����, delete���� �� crash

		mArray = new int[10];

		// �޸� ��� copy, �ӵ��� ������ ����. 1�� ���ڿ� ���� �ּҿ� 2���� ���� �ּҷκ��� 3�� ���ڿ� ���� ����Ʈ �� ��ŭ �޸� ����
		memcpy(mArray, ref.mArray, sizeof(int) * 10);	

		mAttack = ref.mAttack;
		mDefense = ref.mDefense;
		mHP = ref.mHP;
		mHPMax = ref.mHPMax;
		strcpy_s(mName, ref.mName);
	}

	/*
	�̵� ������
	���ο� ������Ʈ�� �������� �ٲ� �ִ� �� (������ ����)
	��ü�� �����ϰų� return�� �� �ӽ� ��ü�� ������ ��
	&& Ÿ���� ���ڸ� �ް� ��
	*/
	CPlayer(CPlayer&& other)
	{
		mAttack = other.mAttack;
	}


	~CPlayer()
	{
		delete[] mArray;
		std::cout << "CPlayer �Ҹ���" << std::endl;
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
		//std::cout << "���ݷ� : " << this->mAttack << std::endl;
		std::cout << "���ݷ� : " << mAttack << std::endl;	// Ŭ������ ��� ������ this-> �� ������ �� ����
	}

	CPlayer SetTest(CPlayer player)
	{
		return player;
	}

private:
	// �����ϸ鼭 �ʱ�ȭ
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
	// Ŭ���� ����� �� ��� �� Ŭ������ 1�� �ƴ� �� ����
	// ������ �⺻���� �� Ŭ������ ũ�Ⱑ 1����Ʈ�� (����ü�� ��������)
	// ��� �Լ��� Ŭ������ ũ�⿡ ������ ���� ����
	std::cout << sizeof(CEmpty) << std::endl;

	CPlayer player;
	CPlayer player1("�Է��� �̸�");
	CPlayer player2("�̸�", 10, 20);
	CPlayer* player3 = new CPlayer("�̸�", 30, 40);
	CPlayer player4(player2);

	// class���� ���� ����
	// Ŭ���������� ������ ������ ��ü�� ��� ���� ���� ���� ��ü�� ��� ������ �����ϴ°���
	//player4 = player1;		// ���� ����, �����Լ� ȣ�� operator

	// ����� ���ÿ� ������ �ص� ���� �����ڰ� ��. ������ �ܼ� ������ ���� ������ x
	CPlayer player5 = player1;	// ���� ������

	//player5.SetTest(CPlayer());
	

	/*
	Ŭ���� ��� �Լ��� �ּҴ� 1�� ����
	��� �Լ����� ȣ���ϴ� ��ü�� ��������� ��Ȯ�ϰ� ����� �� �ִ� ������ this ����
	this�� �ڱ��ڽ��� ������
	�Ʒ��� ���� ȣ���� �ϰ� �Ǹ� CPlayer Ŭ������ Output �Լ��� ȣ���� �� player4 ��ü�� �޸� �ּҸ� this�� �־ ȣ���Ѵٴ� �ǹ�
	��, Ŭ������ ��� �Լ��� ȣ���ϱ� ���ؼ� �ݵ�� this�� �־��� ��ü�� �̿��Ͽ� ȣ���� �ؾ� ��
	*/
	player.Output();
	player1.Output();
	player4.Output();
	//CPlayer playerArray[10] = {};
	//CPlayer* PlayerDynamic = new CPlayer;		
	// PlayerDynamic�� �޸� �ּҸ� ��� ���� ������ ������ �� ��ü�� �ƴ�
	// new CPlayer�� ���� ���� �����Ҵ� �� ��ü�� return�� �ּҰ��� ��� �ִ� ������ ������

	//PlayerDynamic->SetHP(300);

	//player.mAttack = 10;
	//player.mDefense = 100;		// private�� ���� �Ұ���
	player.SetHP(500);
	player.SetAttack(50);

	std::cout << player.GetAttack() << std::endl;
	player.Output();
	
	delete player3;
	//delete PlayerDynamic;

	return 0;
}