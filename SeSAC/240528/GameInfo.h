//#pragma once		// �� ���� ���Խ�Ű���� ��

// #ifdef �� �ڿ� ���� ������ #define���� ���ǵǾ� �ִ��� �Ǵ���
// #ifndef #define ���ǰ� ���� ���
#define TEST 1

#ifdef TEST

#else

#endif

#ifndef GAMEINFO
#define GAMEINFO

#include <iostream>

namespace EItemType
{
	enum Type
	{
		Weapon,
		Armor
	};
}

#endif