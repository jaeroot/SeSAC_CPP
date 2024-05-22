#include <iostream>

/*
�տ� #�� ���� : ��ó����
��ó�� : ������ �ϱ� ���� ó��
define���� ���ǵ� ������ ����� ������ �ڵ带 ��������
define�� �ݵ�� ���ٷ� �ۼ��ؾ� ��
define ���� - ������� �� ��

F9 - break point, �ߴ���
F5 - ����� ���� ����
����� Debug���� �Ǿ� �־�� ����װ� ����� ��. Release ����� ����װ� ����� ���� ����
������ ���� �Ŀ��� release ���� �� �׽�Ʈ�� �غ��� �� (debug���� �Ǵµ� release���� �ȵǴ� �͵� ����)
Ŭ���̾�Ʈ���� �α׸� ���ܼ�, ���� ����Ʈ�� ������ ��. �α� ����� ���� ������ ũ���� ������ �޸𸮸� ����� dump��°� �������� �ϱ⵵ ��
����� ��, ������� ���� ���� ���� �� �� �ְ�, ȣ�� ������ ���� �Լ��� ȣ��� ������ �� �� ����
�� �پ� ���� - F10
F10�� �Լ��� �־ ������ ���� �ʰ� �� �پ� ������ѹ���
�Լ� ������ ���� �ʹٸ� - F11
*/

#define TEST	10
#define TESTOUTPUT std::cout << "TEST Output" << std::endl;

// define�� ���� �Լ�ó�� �����ϴ� �� ���� �� ����
// �̸� ��ũ�� ��� ��
#define MacroNumber(Num)	std::cout << Num << std::endl;
#define MacroPlus(Num1, Num2)	Num1 + Num2

#define SAFE_DELETE(p)	if(nullptr != p) {delete p; p = nullptr;}
// ���� ���� �ᵵ define���� �� �ٷ� �νĽ�Ű�� ��� : \����
// \�� �Ʒ� �ٿ� �ִ� ������ �ٿ���
#define SAFE_DELETE_ARRAY(p)	\
if (nullptr != p)\
{\
	delete[] p;\
	p = nullptr;\
}

/*
L"1234" - L���� ���ڿ��� 2����Ʈ �����ڵ���
*/
#define TEXT(text)	L##text		// ##�� �� ���ڿ��� �ٿ��ִ� ������ ��

/*
define���� ����ϴ� Ư���� ��ȣ��
*/

void Output()
{
	int Num = 100;

	std::cout << "Output Function" << std::endl;
}

// typedef : Ÿ���� ���������ִ� ���
// �Ʒ��� intŸ���� �������� MyInt�� �������
// inte�� ��밡���ϰ�, MyInt�� �ϸ� int Ÿ�� ������ ������ �� ����
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
	// ���� ������ �ÿ��� 10 ���� �ٿ� ����
	int Number1 = TEST;
	int Number2 = 10;

	// �ڵ带 �������شٰ� �����ϸ� ��
	TESTOUTPUT;

	Output();

	// define�̶� ����� �ص� ���� ������ ������ ����
	MacroNumber(10);
	MacroNumber(3.14f);
	MacroNumber("Macro Test");

	std::cout << MacroPlus(10, 20) << std::endl;
	// MacroPlus(10, "test");

	int* Pointer = nullptr;
	//delete Pointer;		// 100% ũ���ð� ���� ��
	if (nullptr != Pointer)	// �̷��� ���� Pointer = nullptr���� !�� ���԰� �Ǽ����� �� ����� ������ ������ �� ����, �������� ����� ������ ��������
	{
		delete Pointer;
	}

	TEXT("Unicode Text");
	L"Unicode Text";


	// ��۸� ������
	Pointer = new int;
	delete Pointer;
	//*Pointer = 500;		// �̹� delete�� �ּҸ� ������ �־ ����!


	/*
	��������� : ������ ����ų� ������� ������ �о�� �� ���
	c��� ����� fopen_s�� �̿�
	c++����� ifstream, ofstream�� �̿�
	�𸮾��� ��Ƽ�÷������� �� �� �ֵ��� �𸮾��� ���� ����� ������ ����
	*/

	//Alloc(Pointer);
	Alloc1(&Pointer);

	// FILE�� C���� �����ϴ� FileStream�̴�.
	FILE* File = nullptr;

	// ���𰡸� �����ؾ� �ؼ� �ּҸ� �޾ƿ;� �ϴ� ��� ���� ������ ����ϴ� ��� ����
	/*
	���� ���
	����� : ���ذ�α����� ��δ� �����ϰ� ������ ��θ� �־ ����ϴ� ���
	������ : C:\ ó�� ����̺� ���� ���Ŀ��� ��� ��θ� �ۼ��ϴ� ���

	���� ����
	�ؽ�Ʈ ����, ���̳ʸ� ����

	3�� ���ڴ� ���� 1�� Ȥ�� 2���� ������ �� ����
	ù ��° ���� : w, r, a �� �� �ϳ� ���
	w : ������ ����
	r : ������ ����
	a : append ���, ������ �����ϸ� ������ ��� �ش� ������ �ڿ� ���� �߰�, ������ ������ ������ ����

	�� ��° ���� : t, b, +
	t : �ؽ�Ʈ ����
	b : ���̳ʸ� ����

	w+ : ������ ������ �а� ���� �۾��� ��� ��. ������ ���� ����
	r+ : ������ ������ �а� ���� �۾��� ��� ��. ������ ���� ��ȯ
	a+ : ������ ������ ������ �� ������ �а� ���Ⱑ ����. ������ ������ ���� ����

	*/
	fopen_s(&File, "test.txt", "wt");

	// File�� nullptr�� ��� ������ ���� �� ���� ����
	if (File)
	{
		// file�� ����� �� filestream�̶� ��. ���⼱ File ������ filestream�� ����� ����
		fputs("TEXT\n", File);
		fputs("2��° ����\n", File);

		//__LINE__		// ���� �� ��ȣ�� �˷��ִ� ��ũ��, ����
		//__FILE__		// ���� ��� �˷��ִ� ��ũ��, ���ڿ�
		//__FUNCTION__	// �Լ� �̸��� �˷��ִ� ��ũ��, ���ڿ�
		char Msg[256] = {};

		fprintf(File, "%s : %s(%d)\n", __FILE__, __FUNCTION__, __LINE__);	// �α� ���� �� ����

		// filestream�� �ݴ� �Լ� : fclose
		fclose(File);
	}

	fopen_s(&File, "test.txt", "rt");
	if (File)
	{
		char Buffer[256] = {};

		// �� ���� �о�´�. ���๮�ڱ��� �о��
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