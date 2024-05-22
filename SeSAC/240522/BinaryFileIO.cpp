#include <iostream>

struct FItem
{
	char Name[32] = {};	// ��� ���� 0���� �ʱ�ȭ�ϸ� �迭�� �Ѿ�� ������� �ʴ� �̻� ���ڿ��� ������ 0�� �Ǿ� ���ڿ��� ����
	int Option;
};

int main()
{
	/*
	void�� ������ Ÿ�� ���� ���� ����
	void*�� ��� ���� Ÿ���� �޸� �ּҸ� ������ �� ����
	��, �������� �Ұ���
	�޸𸮿� �ܼ��� ���常 �� ��쿡�� void�����Ͱ� ����

	�������� Ÿ���� ũ�⸸ŭ �޸𸮿��� ���� �������°���
	void�� ũ�� ������ ���� �ʱ⿡ �޸𸮿��� �������� ���� ���� �����ϰų� ������ �� ����
	�������� ���� �޸� ũ��� Ÿ���� �ݵ�� �˰� �־�� �� (Ÿ���� ���� �Ǳ� ��, �޸𸮸� �����ϱ⸸ �� ����)
	*/

	int Number = 100;
	int* PointerInt = &Number;
	//float* PointerFloat = &Number;	// ������ Ÿ���� �޶� error �߻�
	float* PointerFloat = (float*)&Number;
	*PointerFloat = 3.14;
	std::cout << Number << std::endl;	// �̻��� ���� ����. int�� float�� ���� �����ϴ� ����� �ٸ�

	void* PointerVoid = &Number;		// void pointer�� �� ��ȯ ���� ��� Ÿ�� ���� ����.
	float NumberFloat = 3.14f;
	PointerVoid = &NumberFloat;
	*((float*)PointerVoid) = 3.1124f;

	FILE* File = nullptr;
	fopen_s(&File, "TestBinary.bin", "wb");

	if (File)
	{
		int Number = 100;
		// parameter : �ּ�, ũ��, ����, FileStream
		fwrite(&Number, sizeof(int), 1, File);

		int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
		fwrite(Array, sizeof(int), 10, File);

		FItem Item;

		// ���ڿ� ����
		// ���ڿ��� ���� \0 (null)�����̴�.
		// \0�� ���ö����� ���ڿ��� ������ �ʰ� ��� �νĵ�
		Item.Name[0] = 'a';
		Item.Name[1] = 'b';
		Item.Name[2] = 'c';
		Item.Name[3] = 0;
		std::cout << Item.Name << std::endl;

		// str, wcs
		// �迭�� ũ�� -1��ŭ�� ����ϴ� ���� ����
		strcpy_s(Item.Name, "���");	// �ѱ�, �Ͼ�, �ѹ� ���� ���� �ϳ� �� 2����Ʈ, �� 11����Ʈ
		Item.Option = 10;
		//std::cout << Item.Name << std::endl;
		//Item.Name = "���";

		// �� ��° ���ڿ� Ÿ�� ��� ���� �־ ��
		fwrite(&Item, sizeof(Item), 1, File);

		fclose(File);
	}
	// txt������ binary ���Ϻ��� �뷮�� �� �����Ѵ�. (ex. 100000 = 6����Ʈ, binary = int = 4����Ʈ)

	fopen_s(&File, "TestBinary.bin", "rb");

	if (File)
	{
		// ���� �뷮 ���ϱ�
		// cursor�� file���ο��� ���������� ���� ��ŭ ��ġ�� ����
		// fseek�� Ŀ���� ��ġ�� �����ų �� �ִ� �Լ�
		// offset : ���������κ��� �󸶳� ��������
		// origin : ������
		// // SEEK_CUR : ���� ��ġ
		// // SEEK_SET : ������
		// // SEEK_END : ������
		// fseek�� ���� ���ϴ� ��ġ�� Ŀ���� �̵����Ѽ� ������ ���� ���� ����
		// �翬�� fseek�� ftell�� txt���Ͽ��� �� �� ����
		fseek(File, 0, SEEK_END);

		// ���� ���� Ŀ���� ��ġ�� ������
		// �� ���� Ŀ���� ��ġ�� �������� ������� �뷮�� ����
		int Cur = ftell(File);
		std::cout << Cur << std::endl;

		// ó������ Ŀ�� ��ġ �ǵ�����
		fseek(File, 0, SEEK_SET);

		// fwrite �� �� �״�� �����ؼ� fread�� ����
		// ���ڰ� ���Ƽ� �Ǽ��� �� ����
		int Number;
		fread(&Number, sizeof(int), 1, File);
		std::cout << Number << std::endl;
		
		int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
		fread(Array, sizeof(int), 10, File);

		FItem Item;
		fread(&Item, sizeof(Item), 1, File);
		std::cout << "�̸� : " << Item.Name << std::endl;
		std::cout << "���ݷ� : " << Item.Option << std::endl;

		fclose(File);
	}

	return 0;
}