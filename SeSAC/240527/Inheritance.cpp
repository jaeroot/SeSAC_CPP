#include <iostream>

/*
��� : Ŭ���� Ȥ�� ����ü ���̿� �θ�� �ڽ��� ���踦 ������ �� �ִ� ���
�ڽ� Ŭ������ �θ� Ŭ������ ���(����, �Լ�)�� �����޾� ����� �� �ְ� ��

��ӱ������� �����ڴ� �θ� -> �ڽ� ������ ȣ���� �ǰ�
�Ҹ��ڴ� �ڽ� -> �θ� ������ ȣ���� ��

protected : Ŭ���� �ܺο����� ������ �Ұ���������, Ŭ���� ���γ� �ڽ� Ŭ���� ���ο����� ���� ����

private : Ŭ���� �ܺ� Ȥ�� �ڽ� Ŭ���� ���ο����� ������ �Ұ����ϰ�, �ش� Ŭ���� ���ο����� ���� ����
*/

class CParent
{
public:
	CParent()
	{
		std::cout << "CParent ������" << std::endl;
	}

	~CParent()
	{
		std::cout << "CParent �Ҹ���" << std::endl;
	}

public:
	int mA;

private:
	int mC;

protected:
	int mD;
};

class CParent1
{

public:
	CParent1()
	{
		std::cout << "CParent1 ������" << std::endl;
	}

	~CParent1()
	{
		std::cout << "CParent1 �Ҹ���" << std::endl;
	}

public:
	int mB;

private:
	int mPrivate;
};

class CChild : public CParent
{

public:
	CChild()
	{
		std::cout << "CChild ������" << std::endl;
	}

	~CChild()
	{
		std::cout << "CChild �Ҹ���" << std::endl;
	}
};

/*
private�� ����� �޾��� �� �θ� Ŭ������ ����� �ܺο��� ���� �Ұ���
��, ���� Ŭ���������� �θ��� public, protected ����� ���� ����
*/
class CChild1 : public CParent, private CParent1			// ���� ��� : �θ� Ŭ������ ���� �� ��� �޴� ��
{
public:
	CChild1()
	{
		mB = 10;
		//mPrivate = 100;
		mA = 10;
		//mC = 5;
		mD = 20;
		std::cout << "CChild1 ������" << std::endl;
	}

	~CChild1()
	{
		std::cout << "CChild1 �Ҹ���" << std::endl;
	}
};

class CChildChild : public CChild
{

public:
	CChildChild()
	{
		std::cout << "CChildChild ������" << std::endl;
	}

	~CChildChild()
	{
		std::cout << "CChildChild �Ҹ���" << std::endl;
	}
};

/*
�Լ� �������̵�(�Լ� ������) : Ŭ������ ����ü�� ��Ӱ��踦 �����ϰ� ���� �� ��� ������ ����
�� virtual�� �ƴϾ ��

������ : ��� ���迡 �ִ� Ŭ������ �θ� Ȥ�� �ڽ� Ÿ������ ����ȯ�� ������ ��
�ڽ� -> �θ� ����ȯ : �� ĳ����
�θ� -> �ڽ� ����ȯ : �ٿ� ĳ����

ĳ���� 4�ѻ�
static_cast : �Ϲ����� �� ��ȯ (int, float)
const_cast : const ���� ����
reinterpret_cast : ���� �� ��ȯ
dynamic_cast : ��� ���迡�� ��� (�ٸ� type���� casting ��, nullptr return. ����� �� casting�̸� �ּҰ� return), ����ó�� ����, ���������� down-casting ����

���� �Լ� ���� : ���� Ŭ����
���� �Լ� ���� : ��� ���� Ŭ����
dynamic_cast�� ���� Ŭ������ ��� ���� (���� �Լ��� �־�� ��)

virtual Ű���带 Ȱ���Ͽ� Ŭ������ ��� �Լ��� �Ҹ��ڸ� ���� �Լ��� ���� �� ����
�����Լ��� �θ�Ŭ������ �����Լ��� �ڽ�Ŭ������ ������ �ϸ� �ڽ��� �Լ��� ȣ��� �� �ֵ��� �ϴ� ���

�����Լ��� ������ �ִ� Ŭ���� : �θ� �����Լ��� �ִٸ� �θ�, �ڽ� Ŭ���� ��� �����Լ��� ������ �ִ� �Ͱ� ����
�����Լ��� ������ �ִ� Ŭ������ �����Լ� ���̺��� ������ ��
�����Լ� ���̺��� Ŭ������ ������� �����Լ��� �޸� �ּҸ� �����ϰ� �ִ� �迭��

�����Լ��� ȣ���ϰ� �Ǹ� ���� �ش� Ÿ���� �����Լ� ���̺��� �����ϰ� ��
casting�ؼ� Ÿ���� �ٲ���� vtable ������ �ٲ��� ����
vfptr (virtual function pointer)
�����Լ� ���̺� �� �ִ� �Լ��� �ּҸ� �����ͼ� ȣ���� ���ֱ� ������ �����Լ��� �ڽĿ� ������ �Ǿ��ٸ� �ش� �Լ��� ȣ��Ǵ� ���

*/

class CEmpty
{
public:
	CEmpty()
	{
		std::cout << "CEmpty ������" << std::endl;
	}

	virtual ~CEmpty()
	{
		std::cout << "CEmpty �Ҹ���" << std::endl;
	}

public:
	virtual void Output()
	{
		std::cout << "CEmpty Output" << std::endl;
	}

	// ���� ���� �Լ� : �����Լ� �ڿ� =0�� �ٿ��ָ� ���� �����Լ��� ��
	// ���� ���� �Լ��� �ڽ� Ŭ������ ������ ������ �ؾ� ��
	// ���� ���� �Լ��� ������ �ִ� Ŭ������ �߻� Ŭ������� ��
	// �߻� Ŭ������ ��ü ������ �Ұ�����
	// �ڽ� Ŭ�������� �θ��� ���� ���� �Լ��� ������ ���� ���� ���, �ڽ� Ŭ������ �߻� Ŭ������ ��
	// ���� ���� �Լ��� ������ ���� �� ����
	// abstract Ű���带 ���� ���� ���� �Լ��� ��� �߻� Ŭ������ ���� �� ����
	virtual void OutputPure() = 0;

	virtual void OutputPure1() = 0
	{

	}
};

class CEmptyChild : public CEmpty
{
public:
	CEmptyChild()
	{
		std::cout << "CEmptyChild ������" << std::endl;
	}

	~CEmptyChild()
	{
		std::cout << "CEmptyChild �Ҹ���" << std::endl;
	}

public:
	// override Ű���� : �� �Լ��� �θ� ������� �Լ��� ������ �ϴ� �Լ���� ��������� �˷���
	// ���� �θ� ���� �Լ��� ������ٸ� error�� �߻���Ŵ

	// final Ű���� : �ٸ� �ڽ� Ŭ�������� �� �̻� ������ �Ұ�
	virtual void Output() override final
	{
		//CEmpty::Output();

		std::cout << "CEmptyChild Output" << std::endl;
	}

	void Output(int test)
	{
		std::cout << "CEmptyChild Output test" << std::endl;
	}

	virtual void OutputPure()
	{

	}

	virtual void OutputPure1()
	{

	}
};

class CEmptyChild1 : public CEmpty
{
public:
	CEmptyChild1()
	{
		std::cout << "CEmptyChild1 ������" << std::endl;
	}

	~CEmptyChild1()
	{
		std::cout << "CEmptyChild1 �Ҹ���" << std::endl;
	}

	virtual void OutputPure()
	{

	}

	virtual void OutputPure1()
	{

	}
};

class CEmptyChildChild : public CEmptyChild
{
public:
	CEmptyChildChild()
	{
		std::cout << "CEmptyChildChild ������" << std::endl;
	}

	~CEmptyChildChild()
	{
		std::cout << "CEmptyChildChild �Ҹ���" << std::endl;
	}

public:
	//void Output()
	//{
	//	std::cout << ("CEmptyChildChild") << std::endl;
	//}

};

// Ŭ���� ���� �� Ŭ���� �̸� �����ʿ� abstract  Ű���带 �ٿ��ָ� �� Ŭ������ �߻� Ŭ������ ��
// ���� ���� �Լ��� ��� �߻� Ŭ������ �������
class CAbstractClass abstract
{

};

// ���� ���� �Լ��� ������ abstract �ٿ��� ��
class CAbstractClass1 abstract
{
public:
	virtual void Output() = 0;
};

// �Լ��� =0��� abstract Ű���带 �ٿ��� ���� ���� �Լ��� ���� ���� ����
class CAbstractClass2
{
public:
	virtual void Output() abstract;
};

int main()
{
	//CAbstractClass c1;

	// ������ �Ҹ��� ���� Ȯ��
	//CChild child;
	//CChild1 child1;
	//CChildChild childchild;

	// ���� ����� ����
	// �θ� Ŭ���� �� �̸��� �ߺ��� ��� ��ȣ���� �� ����
	//CChild1 child1;
	//child1.mA = 50;
	// private���� ����� ������, �θ� Ŭ�������� public���� �Ǿ� �ִ� �ϴ��� �ܺο��� ������ ���� ����
	//child1.mB = 100;

	//std::cout << std::endl;
	//std::cout << "CParent : " << sizeof(CParent) << std::endl;
	//std::cout << "CParent1 : " << sizeof(CParent1) << std::endl;
	//std::cout << "CChild : " << sizeof(CChild) << std::endl;
	//std::cout << "CChild1 : " << sizeof(CChild1) << std::endl;
	//std::cout << "CChildChild : " << sizeof(CChildChild) << std::endl;
	//std::cout << "Empty : " << sizeof(CEmpty) << std::endl;
	//std::cout << "CEmptyChild : " << sizeof(CEmptyChild) << std::endl;

	/*std::cout << std::endl;
	CEmpty Empty;
	Empty.Output();

	CEmptyChild EmptyChild;
	EmptyChild.Output();*/
	//CEmptyChild.CEmpty::Output();

	// ��ĳ����
	CEmptyChild child;
	CEmpty* Parent = (CEmpty*)&child;
	CEmptyChild1* DownChild1 = (CEmptyChild1*)Parent;
	CEmptyChild1* DownChildDynamic1 = dynamic_cast<CEmptyChild1*>(Parent);

	CEmpty* ParentArray[10] = {};

	ParentArray[0] = new CEmptyChild;
	ParentArray[1] = new CEmptyChild1;
	ParentArray[2] = new CEmptyChild;

	// �����ǵ� �Լ��� ȣ���ϴ� ��ü�� Ÿ�Կ� ���� ȣ��Ǵ� �Լ��� �޶���
	// �Ʒ��� Ÿ���� CEmpty Ÿ�� �����͸� �̿��Ͽ� ȣ���ϱ� ������ ���� ������ ��ü�� Child�� �ϴ��� CEmpty Ŭ������ �Լ��� ȣ���
	ParentArray[0]->Output();
	ParentArray[1]->Output();

	delete ParentArray[0];
	delete ParentArray[1];
	delete ParentArray[2];

	// ���� �Լ� ���� �� ��ü ������ memcpy, memset ����
	// ���� �Լ� ���̺���� �����ϰų� �о���� �� ����

	// vtable�� ��ü���� ���� x
	// Ŭ�������� �����ż� �ش� �ּҸ� ������ �ִ� ����


	std::cout << std::endl;

	return 0;
}