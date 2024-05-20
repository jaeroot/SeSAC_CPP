#include <iostream>

int main()
{
	/*
	����ü : ���� Ÿ���� �������� �ϳ��� ��� ����� �� �ְ� ���ִ� ���

	struct ����ü��
	{
		������
	};


	*/

	enum Type : unsigned char // 1����Ʈ�� �������
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

		// ����ü ��� ����
		// ������Ʈ - �Ӽ� - C/C++ - �ڵ����
		// ��� ������ ���� ū �ڷ��� �������� �������
		// �������� ���� ����Ʈ������ �ϴ� ��찡 ����
		// Ŭ�� - ���� ���� ����� �� ���� ũ�⸦ ���Ͻ��Ѽ� �۾��ؾ� ��
	};

	//FPlayer Player = {};	// �迭ó�� ���� 0���� �ʱ�ȭ
	FPlayer Player = { "���", Knight, 100 };	// defense�� 0, �������� �־��� ������ �ʱ�ȭ
	// ����ü ���� �������� ����� ���ÿ� �ʱ�ȭ �� �� ����

	// ����ü�� ũ��� ����ü�� �̷�� �ִ� ��� �������� ���հ� ����
	FPlayer PlayerArray[10];

	Player.Job = Knight;
	Player.Item.Option = 30;
	std::cout << Player.Attack << std::endl;
	std::cout << sizeof(Type) << std::endl;
	std::cout << sizeof(FPlayer) << std::endl;

	return 0;
}