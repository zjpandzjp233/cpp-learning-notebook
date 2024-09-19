#include<iostream>
#include<string>
using namespace std;

//父类与子类的构造和析构顺序
class Coutry
{
public:
	Coutry()
	{
		name = "China";
	}
	string name;
};
class School
{
public:
	School() 
	{
		cout << "School的构造函数" << endl;
		age = 50;
	}
	~School() 
	{
		cout << "School的析构函数" << endl;
	}

	//string name;
	static int a;
	int age;
private:
	int 面积;
};
int School::a=99;
class Studens :public School,public Coutry//公共继承。子类继承父类，子类有时候也叫派生类。父类有时候叫基类
{
public:
	Studens()
	{
		cout << "Studens的构造函数" << endl;
		age = 18;
	}
	~Studens()
	{
		cout << "Studens的析构函数" << endl;
	}
	int age;
	int ID;
};

void 父类与子类的构造和析构顺序()
{
	Studens s;
}

class 动物
{
public:
	int age;
	动物()
	{
		age = 9;
	}
};
class 狼 :virtual public 动物//涉及到指针
{};
class 狗 :virtual public 动物
{};
class 狼狗:public 狼 ,public 狗 
{};

int main()
{
	/*
	Studens student1;
	//student1.name = "jackchen";

	cout << sizeof(student1);//12//private的内容也被继承，只不过被编译器隐藏
	
	父类与子类的构造和析构顺序();

	   // School的构造函数
		//Studens的构造函数
		//Studens的析构函数
		//School的析构函数

	Studens stu;
	cout << stu.School::age<<endl;//同名父与子同名对象访问区分方法
	cout << stu.age << endl;//访问的是子类
	//上面规则和函数的规则差不多。
	//如果子类中出现和父类同名的成员函数。子类的同名成员会隐藏掉父类中所有同名成员函数。
	//然后要使用作用域来引用
	
	Studens s;
	cout << Studens::School::a << endl;
	cout << School::a << endl;//结果一样
	*/

	狼狗 lg;
	lg.age = 9;
	cout << lg.age << endl;//9

	lg.狗::age=8;
	cout << lg.age << endl;//8

	lg.狼::age = 18;
	cout << lg.age << endl;//18

	lg.狼::动物::age = 28;
	cout << lg.age << endl;//28

	lg.age = 19;
	cout << lg.狼::动物::age << endl;//19

	system("pause");
	return 0;
}