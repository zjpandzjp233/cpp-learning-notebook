#include <iostream>
#include<string>
using namespace std;

//��̬��̬����������
//1.�м̳й�ϵ
//2.������д�����麯��

class Animal
{
public:
	virtual void speak()//������һ���麯��ָ�� vfptr
	{
		cout << "Animal speaking ." << endl;
	}
	Animal()
	{
		cout << "Animal���캯��" << endl;
	}

	//virtual~Animal()//��������һͬɾ�� //������д�� //û���������������������������
	//{
	//	cout << "Animal��������" << endl;
	//}

	virtual~Animal() = 0;//��������д�� //���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
};
Animal::~Animal()//��������д��
{
	cout << "Animal������������" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat���캯������" << endl;
		m_name = new string(name);
	}
	virtual void speak()//virtual ��ʡ�� //��д�˺������滻���̳й������麯��ָ��
	{
		cout << "Cat speaking ." << endl;
	}
	string* m_name;
	Cat()
	{
		cout << "Cat���캯������" << endl;
	}
	~Cat()
	{
		if (m_name != nullptr)
		{
			cout << "Cat��������������" << endl;
			delete m_name;
			m_name = nullptr;
		}
	}
};
void ͨ��������ɾnew�Ӷ���()
{
	Animal* animal = new Cat("Tom");//new��ʱ���Զ��⴫��
	animal->speak();
	delete animal;//��ͨ������������������޷���������һͬɾ��
}

void TestCatToAnimal(Animal& ani)//����ָ�������ָ��������� ��ɶ�̬ʹ������
{
	ani.speak();
}

class AbstractCalculate//ֻҪ������һ�����麯�����ǳ����࣬�޷�ʵ��������
{
public:
	int a;
	int b;
	virtual int result() = 0;//���麯������д�麯��
	int Return9()
	{
		return 9;
	}
};
class Add: public AbstractCalculate//���������д�������еĴ��麯��������Ҳ���ڳ�����
{
	int MyOwn;
	int result()
	{
		return a + b;
	}
};
void ���麯��ʵ��������()
{
	//AbstractCalculate a;//����
	//new AbstractCalculate;//����
}
void test()
{
	Cat c;
}
int main()
{
	/*
	Cat c;
	TestCatToAnimal(c);//Cat speaking .//��������cat�����speak�������Ǹ��滻
	Animal a;
	TestCatToAnimal(a);//Animal speaking .
	
	cout << sizeof(Animal) << endl;
	
	AbstractCalculate* a = new Add;//��������ࣻ�����virtual���������д�������
	a->a = 8;
	a->b = 9;
	cout << a->result()<<endl;
	cout << a->Return9()<<endl;
	
	delete a;
	
	ͨ��������ɾnew�Ӷ���();
	*/
	//test();
	AbstractCalculate* a = new Add;
	a->a = 2; a->b = 9;
	cout << a.//û��MyOwn
	system("pause");
	return 0;

}