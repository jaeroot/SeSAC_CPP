#include <iostream>

struct FItem
{
	char Name[32] = {};	// 모든 곳을 0으로 초기화하면 배열을 넘어서서 사용하지 않는 이상 문자열이 끝나면 0이 되어 문자열이 끝남
	int Option;
};

int main()
{
	/*
	void는 포인터 타입 변수 선언 가능
	void*는 모든 변수 타입의 메모리 주소를 저장할 수 있음
	단, 역참조가 불가능
	메모리에 단순히 저장만 할 경우에는 void포인터가 좋음

	역참조는 타입의 크기만큼 메모리에서 값을 가져오는것임
	void는 크기 예측이 되지 않기에 메모리에서 역참조를 통해 값을 저장하거나 가져올 수 없음
	역참조할 때는 메모리 크기와 타입을 반드시 알고 있어야 함 (타입은 몰라도 되긴 함, 메모리를 복사하기만 할 때는)
	*/

	int Number = 100;
	int* PointerInt = &Number;
	//float* PointerFloat = &Number;	// 포인터 타입이 달라서 error 발생
	float* PointerFloat = (float*)&Number;
	*PointerFloat = 3.14;
	std::cout << Number << std::endl;	// 이상한 값이 나옴. int와 float는 값을 저장하는 방법이 다름

	void* PointerVoid = &Number;		// void pointer는 형 변환 없이 모든 타입 저장 가능.
	float NumberFloat = 3.14f;
	PointerVoid = &NumberFloat;
	*((float*)PointerVoid) = 3.1124f;

	FILE* File = nullptr;
	fopen_s(&File, "TestBinary.bin", "wb");

	if (File)
	{
		int Number = 100;
		// parameter : 주소, 크기, 개수, FileStream
		fwrite(&Number, sizeof(int), 1, File);

		int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
		fwrite(Array, sizeof(int), 10, File);

		FItem Item;

		// 문자열 복사
		// 문자열의 끝은 \0 (null)문자이다.
		// \0가 나올때까지 문자열이 끝나지 않고 계속 인식됨
		Item.Name[0] = 'a';
		Item.Name[1] = 'b';
		Item.Name[2] = 'c';
		Item.Name[3] = 0;
		std::cout << Item.Name << std::endl;

		// str, wcs
		// 배열의 크기 -1만큼만 사용하는 것이 좋음
		strcpy_s(Item.Name, "목검");	// 한글, 일어, 한문 등은 문자 하나 당 2바이트, 총 11바이트
		Item.Option = 10;
		//std::cout << Item.Name << std::endl;
		//Item.Name = "목검";

		// 두 번째 인자에 타입 대신 변수 넣어도 됨
		fwrite(&Item, sizeof(Item), 1, File);

		fclose(File);
	}
	// txt파일이 binary 파일보다 용량을 더 차지한다. (ex. 100000 = 6바이트, binary = int = 4바이트)

	fopen_s(&File, "TestBinary.bin", "rb");

	if (File)
	{
		// 파일 용량 구하기
		// cursor는 file내부에서 읽을때마다 읽은 만큼 위치가 변함
		// fseek는 커서의 위치를 변경시킬 수 있는 함수
		// offset : 기준점으로부터 얼마나 떨어질지
		// origin : 기준점
		// // SEEK_CUR : 현재 위치
		// // SEEK_SET : 시작점
		// // SEEK_END : 끝지점
		// fseek를 통해 원하는 위치로 커서를 이동시켜서 파일을 읽을 수도 있음
		// 당연히 fseek나 ftell도 txt파일에서 쓸 수 있음
		fseek(File, 0, SEEK_END);

		// 현재 파일 커서의 위치를 꺼내옴
		// 끝 지점 커서의 위치를 꺼내오는 방식으로 용량을 구함
		int Cur = ftell(File);
		std::cout << Cur << std::endl;

		// 처음으로 커서 위치 되돌리기
		fseek(File, 0, SEEK_SET);

		// fwrite 한 걸 그대로 복사해서 fread로 변경
		// 인자가 같아서 실수할 일 적음
		int Number;
		fread(&Number, sizeof(int), 1, File);
		std::cout << Number << std::endl;
		
		int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
		fread(Array, sizeof(int), 10, File);

		FItem Item;
		fread(&Item, sizeof(Item), 1, File);
		std::cout << "이름 : " << Item.Name << std::endl;
		std::cout << "공격력 : " << Item.Option << std::endl;

		fclose(File);
	}

	return 0;
}