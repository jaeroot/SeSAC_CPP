#include "CItem.h"

int main()
{
	CItem item;
	
	EItemType::Type ItemType;




	// 컴파일 단계에서 실행시킬 코드를 구분지어줄 수 있음
#define TEST 1
#ifdef TEST
	std::cout << "test" << std::endl;
#else
	std::cout << "else" << std::endl;
#endif

#if TEST
	std::cout << "TEST" << std::endl;
#else
	std::cout << "else" << std::endl;
#endif


	return 0;
}