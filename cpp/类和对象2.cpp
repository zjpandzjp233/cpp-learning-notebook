#include<iostream>
#include<string>
using namespace std;
//ctrl+k+u取消注释
//空对象占内存 1，用于区分对象在内存的位置。
class person;//                                                      类内友元函数      *****必须先声明*******下面gays里person不报错

class gays
{
	public:
	person* p;
	void VisitPrivate();
};

class person
{
	friend ostream& operator<<(ostream& cout, person& p);
	
	friend void gays::VisitPrivate(); // 如果上面没有声明gays，这里就无从引用gays::
	friend void 友元2(person* p);//好朋友声明
	friend class girlfriend;
	
	
public:
	static int age;//静态成员变量，不属类的对象上，不增加类的size
	int password ;
	mutable int sex = 1;//可在const函数里变
	
	person():place("bedroom"),height(1.8)
	{
		

	}
	person(int password)
	{
		//this指针指向被调用的成员函数所属的对象
		this->password = password;
		
	}
	void func()const//不增加size，和对象成员变量分开了存储//这里的const可以保证成员不被修改，使得this变成常量指针常量
	{//this指针是指针常量，指向不可修改
		if (this == nullptr)//防止空指针调函数，增加代码健壮性
		{
			return;
		}
		cout << "不含变量的成员函数运行了" << endl;//空指针无法访问有含成员变量的函数，因为空指针没有创建出来成员变量。
		this->sex = 0;
	}
	//person operator+(person& p)  //运算符重载
	//{
	//	person temp;
	//	temp.password = this->password + p.password;
	//	return temp;
	//}
	static void func2()//不增加size，同上
	{
		
	}

	person& personaddage(person& p)//引用return不触发拷贝，如果去掉这一行的&，使得41行输出20，因为 
	{                             //返回类型是类的时候，会触发拷贝函数，返回一个与原对象无关的复制出来的对象
		this->password += p.password;
		return *this;//this指向p22本身 *this是对象本身。
	}
	person& operator++()//重载前置加加，不必传参，这里就涉及一个参数，而且还是定义在成员的函数
	{
		++height;
		return *this;
	}
	person& operator++(int)//int表示占位参数，可以用于区分前置和后置递增//不能返回引用，这里temp是局部变量
	{
		//先记录当时结果
		 person* temp=new person;
		//后递增
		height++;
		return *temp;
	}
	
private:
	string place;
	float height;
};
void gays::VisitPrivate()//               类内友元函数 *******函数内容写在person类后******因为这样才能在声明为友元后访问private
{
	p = new person;
	cout << p->place << endl;
}
class girlfriend
{
public:
	person* m_p;
	int age;
	girlfriend();
	void visitbedroom();
	~girlfriend()
	{
		delete m_p;
	}
};
girlfriend::girlfriend()//类外构造
{
	age = 18;
	m_p = new person;
}
void girlfriend::visitbedroom()//类外函数
{
	cout<<m_p->place;
}

void 空指针访问成员函数()
{
	person* p = nullptr;

	p->func();

	const person p27;//常对象只可以调常函数,静态函数，修改静态变量
	//p27->age = 100;//不可改
	p27.sex = 0;
	p27.func();//可以
}
void 友元()
{
	person p;
	友元2(& p);
}
void 友元2(person* p)
{
	cout << p->place << endl;

}
int person::age = 99;
person operator+(person& a, person& b)//运算符重载
{
	person temp;
	temp.password = a.password + b.password;
	return temp;
}
person operator+( int num, person& p)  //operator+函数重载//参数次序很重要
{
	person temp;
	temp.password = p.password + num;
	return temp;
}
//         << 叫 左移运算符
//ostream& operator<<(ostream &cout,person&p)//本质operator<<(cout,p)简化cout<<p //cout全局只有一个，这里引用
//{
//	cout << p.password;
//	return cout;//返回cout的引用
//}
ostream& operator<<(ostream& cout, person& p)//也可以，cout只是一个名字，关键是定义了<<左右两边的内容，
{//                                         <<左边若是ostream里的,右边是person类的，系统就会调用到这个函数
	//cout << p.password;
	cout << p.height;//实际生效栏
	return cout;//返回cout的引用,为了链式调用
}

int main()
{
	/*
	person p;
	cout << sizeof(p);
	
	person p(888);
	cout << p.password;
	
	person p11(10);
	person p22(10);
	p22.personaddage(p11).personaddage(p11).personaddage(p11);
	cout << p22.password << endl;
	

	空指针访问成员函数();
	
	友元();
	
	girlfriend gg;
	gg.visitbedroom();
	
	gays g;
	g.VisitPrivate();
	
	person a;
	person b;
	a.password = 11111;
	b.password = 22222;
	//person c= a + b;//本质：person c=a.operator+(b);成员函数   person c=operator+(a,b);全局函数
	person c = 1+a;
	//cout << c.password << endl;
	cout << a << endl;//如果没有返回ostream里的cout的引用，这里将无法使用endl，这里形成了链式调用
	*/
	person p;
	
	cout <<p++<<endl;
	cout << p;
	
	system("pause");
	return 0;
}
//在 C++ 中，运算符重载可以作为成员函数，也可以作为全局函数。
//但是，++ 运算符（以及其他一些运算符，如 --、 = 、[]、() 和->）必须被重载为成员函数。
//这是由 C++ 的语言规则决定的。
//当你在类外部尝试重载这些运算符时，
//编译器会报错，因为它们必须作为类的成员函数来实现。
//这样做的一个原因是，这些运算符通常需要访问类的私有成员。
//如果它们被定义为全局函数，那么它们将无法访问这些私有成员（除非你声明它们为友元函数）。