#include <iostream>
#include <fstream>

int main()
{
	// io file stream
	//std::ifstream;
	//std::ofstream;
	// 함수가 종료되면 자동으로 close 해줌

	std::ofstream OutStream("ofstreamtest.txt");

	// 이 파일이 제대로 열렸는지 판단
	if (OutStream.is_open())
	{
		OutStream << "문자열 추가\n";
		OutStream << "두번째 줄 추가\n";

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