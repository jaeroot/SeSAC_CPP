#include <iostream>

/*
앞에 #이 붙음 : 전처리기
전처리 : 컴파일 하기 전에 처리
define으로 정의된 내용을 사용한 공간에 코드를 복사해줌
define은 반드시 한줄로 작성해야 함
define 단점 - 디버깅이 안 됨

F9 - break point, 중단점
F5 - 디버그 모드로 실행
상단의 Debug모드로 되어 있어야 디버그가 제대로 됨. Release 모드라면 디버그가 제대로 되지 않음
개발이 끝난 후에는 release 모드로 꼭 테스트를 해봐야 함 (debug에선 되는데 release에선 안되는 것도 있음)
클라이언트에도 로그를 남겨서, 오류 리포트를 보내게 함. 로그 남기기 전에 죽으면 크래시 상태의 메모리를 기록한 dump라는걸 보내도록 하기도 함
디버그 시, 조사식을 통해 변수 값을 볼 수 있고, 호출 스택을 통해 함수가 호출된 순서를 볼 수 있음
한 줄씩 실행 - F10
F10은 함수가 있어도 안으로 들어가지 않고 한 줄씩 실행시켜버림
함수 안으로 들어가고 싶다면 - F11
*/

#define TEST	10
#define TESTOUTPUT std::cout << "TEST Output" << std::endl;

// define을 통해 함수처럼 동작하는 걸 만들 수 있음
// 이를 매크로 라고 함
#define MacroNumber(Num)	std::cout << Num << std::endl;
#define MacroPlus(Num1, Num2)	Num1 + Num2

#define SAFE_DELETE(p)	if(nullptr != p) {delete p; p = nullptr;}
// 여러 줄을 써도 define에서 한 줄로 인식시키는 방법 : \쓰기
// \는 아래 줄에 있는 내용을 붙여줌
#define SAFE_DELETE_ARRAY(p)	\
if (nullptr != p)\
{\
	delete[] p;\
	p = nullptr;\
}

/*
L"1234" - L붙은 문자열은 2바이트 유니코드임
*/
#define TEXT(text)	L##text		// ##은 두 문자열을 붙여주는 역할을 함

/*
define에서 사용하는 특수한 기호들
*/

void Output()
{
	int Num = 100;

	std::cout << "Output Function" << std::endl;
}

// typedef : 타입을 재정의해주는 기능
// 아래는 int타입을 재정의한 MyInt를 만들었음
// inte도 사용가능하고, MyInt를 하면 int 타입 변수를 선언할 수 있음
typedef int MyInt;

void Alloc(int* All)
{
	All = new int;
}

void Alloc1(int** All)
{
	*All = new int;
}

int main()
{
	// 실제 컴파일 시에는 10 값을 붙여 넣음
	int Number1 = TEST;
	int Number2 = 10;

	// 코드를 복사해준다고 생각하면 됨
	TESTOUTPUT;

	Output();

	// define이라 디버깅 해도 안의 내용이 보이지 않음
	MacroNumber(10);
	MacroNumber(3.14f);
	MacroNumber("Macro Test");

	std::cout << MacroPlus(10, 20) << std::endl;
	// MacroPlus(10, "test");

	int* Pointer = nullptr;
	//delete Pointer;		// 100% 크래시가 나게 됨
	if (nullptr != Pointer)	// 이렇게 쓰면 Pointer = nullptr같이 !를 빼먹고 실수했을 때 생기는 문제를 방지할 수 있음, 변수보다 상수가 가급적 왼쪽으로
	{
		delete Pointer;
	}

	TEXT("Unicode Text");
	L"Unicode Text";


	// 댕글링 포인터
	Pointer = new int;
	delete Pointer;
	//*Pointer = 500;		// 이미 delete된 주소를 가지고 있어서 위험!


	/*
	파일입출력 : 파일을 만들거나 만들어진 파일을 읽어올 때 사용
	c언어 방식은 fopen_s를 이용
	c++방식은 ifstream, ofstream을 이용
	언리얼은 멀티플랫폼에서 쓸 수 있도록 언리얼만의 공용 입출력 구조를 만듦
	*/

	//Alloc(Pointer);
	Alloc1(&Pointer);

	// FILE은 C언어에서 제공하는 FileStream이다.
	FILE* File = nullptr;

	// 무언가를 생성해야 해서 주소를 받아와야 하는 경우 더블 포인터 사용하는 경우 많음
	/*
	파일 경로
	상대경로 : 기준경로까지의 경로는 무시하고 나머지 경로만 넣어서 사용하는 방식
	절대경로 : C:\ 처럼 드라이브 부터 거쳐오는 모든 경로를 작성하는 방식

	파일 종류
	텍스트 파일, 바이너리 파일

	3번 인자는 문자 1개 혹은 2개로 구성될 수 있음
	첫 번째 글자 : w, r, a 셋 중 하나 사용
	w : 파일을 만듦
	r : 파일을 읽음
	a : append 기능, 파일이 존재하면 파일을 열어서 해당 파일의 뒤에 내용 추가, 파일이 없으면 파일을 만듦

	두 번째 글자 : t, b, +
	t : 텍스트 파일
	b : 바이너리 파일

	w+ : 파일이 있으면 읽고 쓰는 작업을 모두 함. 없으면 새로 만듦
	r+ : 파일이 있으면 읽고 쓰는 작업을 모두 함. 없으면 에러 반환
	a+ : 파일이 있으면 파일의 맨 끝부터 읽고 쓰기가 가능. 파일이 없으면 새로 만듦

	*/
	fopen_s(&File, "test.txt", "wt");

	// File이 nullptr일 경우 파일을 만들 수 없는 것임
	if (File)
	{
		// file과 연결된 걸 filestream이라 함. 여기선 File 변수가 filestream이 연결돼 있음
		fputs("TEXT\n", File);
		fputs("2번째 저장\n", File);

		//__LINE__		// 현재 줄 번호를 알려주는 매크로, 정수
		//__FILE__		// 파일 경로 알려주는 매크로, 문자열
		//__FUNCTION__	// 함수 이름을 알려주는 매크로, 문자열
		char Msg[256] = {};

		fprintf(File, "%s : %s(%d)\n", __FILE__, __FUNCTION__, __LINE__);	// 로그 남길 때 좋음

		// filestream을 닫는 함수 : fclose
		fclose(File);
	}

	fopen_s(&File, "test.txt", "rt");
	if (File)
	{
		char Buffer[256] = {};

		// 한 줄을 읽어온다. 개행문자까지 읽어옴
		fgets(Buffer, 256, File);
		std::cout << Buffer;

		fgets(Buffer, 256, File);
		std::cout << Buffer;

		fgets(Buffer, 256, File);
		std::cout << Buffer;

		fclose(File);
	}

	return 0;
}