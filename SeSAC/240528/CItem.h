#pragma once

#include "GameInfo.h"
// ��ȯ ���� ������ ��
//#include "CMonster.h"

// ���� ���� ��, ������ Ÿ���� ����. ��ü�� ���� �ȵ�
// cpp ���Ͽ��� ����Ϸ��� include ���־�� ��
class CMonster;

class CItem
{
public:
	CItem();
	~CItem();

protected:
	CMonster* mMonster;
	EItemType::Type mType;

public:
	void Output();
	void Output1();
};

