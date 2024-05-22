#include <iostream>
#include <fstream>

int main()
{
	// io file stream
	//std::ifstream;
	//std::ofstream;
	// �Լ��� ����Ǹ� �ڵ����� close ����

	std::ofstream OutStream("ofstreamtest.txt");

	// �� ������ ����� ���ȴ��� �Ǵ�
	if (OutStream.is_open())
	{
		OutStream << "���ڿ� �߰�\n";
		OutStream << "�ι�° �� �߰�\n";

		OutStream.close();
	}


	std::ifstream InStream("ofstreamtest.txt");
	if (InStream.is_open())
	{
		char Text[256] = {};
		InStream >> Text;
		//InStream.read();
		//InStream.getline(Text, 10);

		//std::string str;
		//InStream >> str;
		//InStream.getline(Text, 12);

		std::cout << Text << std::endl;
		//std::cout << str << std::endl;

		InStream.close();
	}
																									
	std::ofstream OutStreamBinary("ofstreamtest.bin", std::ios::binary);
	if (OutStreamBinary.is_open())
	{
		float NumberFloat = 3.14f;

		OutStreamBinary.write((const char*)&NumberFloat, sizeof(float));

		OutStreamBinary.close();
	}

	std::ifstream InStreamBinary("ofstreamtest.bin", std::ios::binary);
	if (InStreamBinary.is_open())
	{
		float NumberFloat;
		InStreamBinary.read((char*)&NumberFloat, sizeof(float));
		std::cout << NumberFloat << std::endl;

		InStreamBinary.close();
	}

	return 0;
}