#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	int* age;
	int money;

	person()
	{
		
	}
	person(int a5)
	{
		age = new int(a5);
		money = a5;
	}
	void ptp(person& p)//���ŷ�
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
		int* temp = new int(*p.age);
		age = temp;
	}
	person& operator=(person& p)//���صĵȺ������Ӧ�÷���������ã�class_name& ������������ʽ��ֵ��
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
		age = new int(*p.age);
		return *this;
	}
	bool operator==(person& p)//���ع�ϵ�����
	{
		if (this->money == p.money)
		{
			return true;
		}
		else { return false; }
	}
	int operator()(int a,int b)//���غ������������
	{
		return a + b;
	}
	~person()
	{
		if (age != nullptr)
		{
			delete age;
			age = NULL;
		}
	}
};

void test()
{
	/*
	person p1(18);
	person p2(28);
	person p3(99);
	p3=p1 = p2;
	cout << *p1.age << endl;
	cout << *p2.age << endl;
	cout << *p3.age << endl;
	
	person p1(999);
	person p2(99);
	if (p1 == p2)
	{
		cout << ">" << endl;
	}
	*/
	person pp;
	cout<<pp(2,3)<<endl;//�º���
	cout << person(3) (8, 9)<<endl;//�������󣬴�������һ�б�ɾ�������Ե����������.��person��3��ֱ�ӿ�����һ������p����
	
}
int main()
{
	
	test();
	system("pause");
	return 0;

}