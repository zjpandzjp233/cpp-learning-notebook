#include <iostream>
#include<string>
using namespace std;

//动态多态满足条件：
//1.有继承关系
//2.子类重写父类虚函数

class Animal
{
public:
	virtual void speak()//本质是一个虚函数指针 vfptr
	{
		cout << "Animal speaking ." << endl;
	}
	Animal()
	{
		cout << "Animal构造函数" << endl;
	}

	//virtual~Animal()//连带子类一同删除 //虚析构写法 //没有这个不会调用派生类的析构函数
	//{
	//	cout << "Animal析构函数" << endl;
	//}

	virtual~Animal() = 0;//纯虚析构写法 //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
};
Animal::~Animal()//纯虚析构写法
{
	cout << "Animal纯虚析构函数" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_name = new string(name);
	}
	virtual void speak()//virtual 可省略 //重写此函数会替换掉继承过来的虚函数指针
	{
		cout << "Cat speaking ." << endl;
	}
	string* m_name;
	Cat()
	{
		cout << "Cat构造函数调用" << endl;
	}
	~Cat()
	{
		if (m_name != nullptr)
		{
			cout << "Cat析构函数调用了" << endl;
			delete m_name;
			m_name = nullptr;
		}
	}
};
void 通过虚析构删new子对象()
{
	Animal* animal = new Cat("Tom");//new类时可以额外传参
	animal->speak();
	delete animal;//不通过父类加虚析构，就无法连带子类一同删除
}

void TestCatToAnimal(Animal& ani)//父类指针或引用指向子类对象 达成多态使用条件
{
	ani.speak();
}

class AbstractCalculate//只要类里有一个纯虚函数就是抽象类，无法实例化对象
{
public:
	int a;
	int b;
	virtual int result() = 0;//纯虚函数，简写虚函数
	int Return9()
	{
		return 9;
	}
};
class Add: public AbstractCalculate//子类必须重写抽象类中的纯虚函数，否则也属于抽象类
{
	int MyOwn;
	int result()
	{
		return a + b;
	}
};
void 纯虚函数实例化对象()
{
	//AbstractCalculate a;//报错
	//new AbstractCalculate;//报错
}
void test()
{
	Cat c;
}
int main()
{
	/*
	Cat c;
	TestCatToAnimal(c);//Cat speaking .//函数调用cat里面的speak，由于那个替换
	Animal a;
	TestCatToAnimal(a);//Animal speaking .
	
	cout << sizeof(Animal) << endl;
	
	AbstractCalculate* a = new Add;//子类给父类；父类的virtual被子类的重写函数替代
	a->a = 8;
	a->b = 9;
	cout << a->result()<<endl;
	cout << a->Return9()<<endl;
	
	delete a;
	
	通过虚析构删new子对象();
	*/
	//test();
	AbstractCalculate* a = new Add;
	a->a = 2; a->b = 9;
	cout << a.//没有MyOwn
	system("pause");
	return 0;

}