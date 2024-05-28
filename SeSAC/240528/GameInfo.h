//#pragma once		// 한 번만 포함시키도록 함

// #ifdef 은 뒤에 오는 내용이 #define으로 정의되어 있는지 판단함
// #ifndef #define 정의가 없을 경우
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