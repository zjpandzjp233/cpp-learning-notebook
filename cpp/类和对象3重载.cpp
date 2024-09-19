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
	void ptp(person& p)//括号法
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
		int* temp = new int(*p.age);
		age = temp;
	}
	person& operator=(person& p)//重载的等号运算符应该返回类的引用（class_name& ），这允许链式赋值。
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
		age = new int(*p.age);
		return *this;
	}
	bool operator==(person& p)//重载关系运算符
	{
		if (this->money == p.money)
		{
			return true;
		}
		else { return false; }
	}
	int operator()(int a,int b)//重载函数调用运算符
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
	cout<<pp(2,3)<<endl;//仿函数
	cout << person(3) (8, 9)<<endl;//匿名对象，创建后下一行被删除。可以调（）运算符.把person（3）直接看作是一个对象p即可
	
}
int main()
{
	
	test();
	system("pause");
	return 0;

}