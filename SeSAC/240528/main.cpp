#include "CItem.h"

int main()
{
	CItem item;
	
	EItemType::Type ItemType;




	// ������ �ܰ迡�� �����ų �ڵ带 ���������� �� ����
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