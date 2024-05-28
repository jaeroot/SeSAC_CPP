#include "CMonster.h"
#include "CItem.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

void CMonster::Output()
{
	mItem->Output();
}
