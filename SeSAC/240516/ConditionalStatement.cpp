#include <iostream>

namespace EJob2
{
	enum Type : unsigned short
	{
		None,
		Knight = 100,
		Archer,
		Magicion
	};
}

int main()
{
	/*
	if�� : Ư�� ������ �����ϰ� ������ true�� ��� �����ϴ� ����

	����
	if (���ǽ�)
	{
		������ �ڵ�
	}

	if (���ǽ�)
		������ �ڵ�

	������ �ڵ尡 1���� ��� �ڵ���(�߰�ȣ)�� ������ �� ����

	else�� else if�� �Բ� ����ϸ� �б�ó���� �� �� ����

	else�� else if�� ���������� ����� �Ұ�����, �ݵ�� if �Ʒ��� �;� ��
	else�� ���� �ʿ� ���� ���� if ���̳� else if ���� ������ false�� ��� ������ ������
	else�� if�� 1���� �ִ� 1���� ���� ��

	else if�� if�� 1���� �������� �� �� ����
	���� if�� else if�� ���ǽ��� false�� ���, ���� else if�� ���ǽ��� üũ�ϴ� ���

	���׿����� : ������ üũ�Ͽ� true�� ���� false�϶� ������ ���� ������ �� ����
	���ǽ� ? true�϶� �� : false�϶� ��;
	*/


	/*
	switch�� : �б�ó���� ������
	��ȣ �ȿ� ���� ���� �������� üũ�ϴ� ����

	switch (����)
	{
	case ���:
		break;
	case ���:
		break;
	default:
		break;
	}

	case�ȿ��� ���� ���� �� �ʱ�ȭ�� �Ϸ��� �ڵ� ��(�߰�ȣ, {})�� ���� ����ؾ� ��
	case 1:
	{
		int Number = 3;
	}
	break;

	case�� ������ ���ڸ� ���°ͺ��� const�� ���ȭ�� �� ������ �ִ� ���� �������� �� ���� (Ȥ�� ������)
	*/


	/*
	������ : ����� �̸��� �ο����ִ� ���
	�������� ��ҵ��� 0���� �����Ͽ� ���� 1�� �����ϰ� ��

	enum �������̸�
	{
		���1,
		���2,
		���3
	};

	enum �������̸�
	{
		���1,			// 0
		���2 = 100,		// 100
		���3,			// 101
		���4			// 102
	};

	�������� ������ ��������� Ÿ���� ��
	����� ���� Ÿ�� : �츮�� ���ϴ� ���� Ÿ���� ����� ��
	�������� �̸��� ���� Ÿ���� ��
	�������� ��Ҵ� ���, �⺻������ 4byte�� ���� (int�� �ν�, ���ϸ� �ٸ� Ÿ������ ������ �� ����)
	*/
	enum EJob
	{
		None,
		Knight = 100,
		Archer,
		Magicion
	};

	int Job = Knight;
	EJob Job1 = Knight;
	// Job1 = 20;		int�� �������� ��� ������ �����ϳ�, ������ Ÿ���� �������� int Ÿ�� ������ �Ұ�����
	Job1 = (EJob)3;		// �� ��ȯ �ؼ��� ����


	/*
	namespace EJob
	{
		enum EJob
		{
			None,
			Knight = 100,
			Archer,
			Magicion
		};
	}
	EJob::Knight;
	EJob::Type = 
	*/

	enum class EJob1 : char
	{
		None,
		Knight,
		Archer,
		Magicion
	};

	std::cout << sizeof(EJob2::Type) << std::endl;
	std::cout << sizeof(EJob1) << std::endl;

	// �Ϲ� �������� int Ÿ�Կ� ������ ��
	// enum class�� �ȵ�, ������ �ܰ迡�� Ÿ���� �Ĳ��� ����
	// enum class�� ���� Ÿ������ �����ϰ� ����, ���� �����ϰ� ����ȯ �ϸ� �Ǳ� ��....
	// int�� ���� �ְ� ����Ҷ��� �Ϲ� �������� ����

	// switch ���� ��, ��ȣ�� enum class ������ Ÿ���� ����, tab �� ���� �ϸ� �ڵ��ϼ� ����, namespace �ȿ� �ִ� �ִ� ������
	/*
	switch (EJob1)
	{
	case EJob1::None:
		break;
	case EJob1::Knight:
		break;
	case EJob1::Archer:
		break;
	case EJob1::Magicion:
		break;
	default:
		break;
	}
	*/


	return 0;
}