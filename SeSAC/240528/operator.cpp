#include <iostream>
#include <assert.h>

/*
operator : ������ ������
Ŭ������ ����ü���� ����� �� �ְ� �Ϲ� �����ڵ� ���� ����



*/

struct FVector
{
	float x;
	float y;
	float z;

	// static ��� ����
	// Ŭ������ ����ü�� static ��� ������ ����� ���, �� ������ �ݵ�� ������(Ŭ���� �ܺ�)���� ������ �Ǿ�� �ϰ�,
	// �� ��� ������ �� Ŭ������ ����ü�� �̿��Ͽ� ������ ��� ��ü�� �����ϸ� ���Ǵ� ������ �������
	// ��, �������� ��� ������ ���� �� ����
	// thread-unsafe �ϱ⿡ ����ȭ ó�� ���ָ� ��
	static FVector result1;

public:
	FVector()
	{

	}

	FVector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	FVector(const FVector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

public:
	// �Ʒ��� ���� ���� stack�� ���������� �Ҵ��ϱ⿡ ��۸� ������ ������ ���� �� ����. ������ ��
	//FVector* aa()
	//{
	//	FVector a;

	//	return &a;
	//}

	// ��� �Լ��� operator �ڿ� const�� �پ������� �� �Լ��� operator������ ��������� ���� ������ �� ����
	const FVector& operator + (const FVector& v) const
	{
		FVector result;

		result1.x = x + v.x;
		result1.y = y + v.y;
		result1.z = z + v.z;

		return result1;
	}

	// operator�� �Լ��̱⿡ �����ε� ����
	const FVector& operator + (float Value) const
	{
		// static FVector result;
		// static�� �Լ����� �����Ǵ� ������ ���� �� ����
		FVector result;

		result1.x = x + Value;
		result1.y = y + Value;
		result1.z = z + Value;

		return result1;
	}

	void operator += (const FVector& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

public:
	FVector& operator = (const FVector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	FVector& operator = (float Value)
	{
		x = Value;
		y = Value;
		z = Value;

		return *this;
	}

	float operator [] (int Index) const
	{
		if (Index == 0)
			return x;

		else if (Index == 1)
			return y;

		else if (Index == 2)
			return z;

		// assert ù ���� : 0 - false�� ������ ����, �� �� �� - true�� ������ �ȳ���
		assert(false);

		return FLT_MAX;
	}

public:
	void Output()
	{
		printf("x = %.5f, y = %.5f, z = %.5f\n", x, y, z);
	}

	// static ��� �Լ��� this�� ����
	// �׷��� ������ �Ϲ� ��������� ����� �� ����
	// static ��� ������ ����� ����
	// static ��� �Լ��� ���� �Լ�ó�� �ν�
	static void OutputStatic()
	{
		//printf("x = %.5f, y = %.5f, z = %.5f", x, y, z);
		printf("OutputStatic FUnction\n");
	}
};

//FVector operator+(const FVector& v1, const FVector& v2)
//{
//	return FVector{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
//}

// data������ ��������� ���� ������ ����.. main ���� ���� �ÿ� �޸𸮿��� ���ŵ�
FVector FVector::result1 = {};

int main()
{
	FVector v1, v2, v3;
	v1.x = 1.0f;
	v1.y = 2.0f;
	v1.z = 3.0f;

	v2.x = 4.0f;
	v2.y = 5.0f;
	v2.z = 6.0f;

	// v1�� + ���۷����� ȣ��
	// ���ڷ� v2�� �Ѱ� ��
	v3 = v1 + v2;

	// const ��ü�� �Ϲ� ��� �Լ��� ȣ���� �� ����
	// ��� �Լ� �ڿ� const�� ���� �Լ��� ȣ�� ����
	// operator ������ �Լ� �ڿ� const�� �ٿ� ��� ��
	const FVector v4 = { 7.0f, 8.0f, 9.0f };
	v3 = v4 + v1;
	v3 = v4 + 100.0f;

	std::cout << v3[1] << std::endl;
	//std::cout << v3[5] << std::endl;

	// static ������ �޸� ũ��� ��ü�� �޸� ũ�⿡ ������ ���� ����
	std::cout << sizeof(FVector) << std::endl;

	// �޸� ������ ������
	std::cout << &v1.result1 << std::endl;
	std::cout << &v2.result1 << std::endl;

	v3.Output();

	v3.OutputStatic();
	v3.result1;

	FVector::result1;
	FVector::OutputStatic();
	
	// ���� �Լ��� & ���̴� �Ⱥ��̴� ����
	// ��� �Լ��� & �ٿ��� ��
	std::cout << FVector::OutputStatic << std::endl;
	std::cout << &FVector::OutputStatic << std::endl;
	//std::cout << FVector::Output << std::endl;		// error

	void (*Func)() = FVector::OutputStatic;
	Func();
	
	void (FVector:: * Func1)() = &FVector::Output;
	
	// �Ϲ� ����Լ��� this�� �������� ��ü�� �ּҰ� �ʿ���
	// �׷��Ƿ� ��ü�� �̿��Ͽ� ȣ�����־�� ��
	//Func1();
	(v3.*Func1)();
	(v1.*Func1)();

	// singleton - static Ȱ�� (������ Ŭ���� ������ ���� �� ���� ��, ���� ������, ������ ������)

	return 0;
}