#pragma once

#include "GameInfo.h"
// 순환 참조 조심할 것
//#include "CMonster.h"

// 전방 선언 시, 포인터 타입은 가능. 객체는 생성 안됨
// cpp 파일에서 사용하려면 include 해주어야 함
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

