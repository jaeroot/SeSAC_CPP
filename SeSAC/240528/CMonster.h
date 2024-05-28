#pragma once

#include "GameInfo.h"

class CItem;

class CMonster
{
public:
	CMonster();
	~CMonster();

	void Output();

private:
	CItem* mItem;
};

