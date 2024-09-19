#include "circle.h"



struct s1
{
private:
	int a=9;
public:
	void aa()
	{
		cout << a;
	}
};

//如果用户定义有参构造函数，C++不再提供默认无参构造函数 ，但是会提供默认拷贝函数
//先被创建的对象后被析构
//如果用户定义了拷贝构造函数，C++不会再提供其他构造函数
class phone
{
public:
	string brand;
	static int ID;
	phone()
	{

	}
	phone(string brands)
	{
		brand = brands;
		cout << "构造函数已调用001" << endl;
	}
	static void IDchages(int a)//静态函数不能访问非静态成员
	{
		ID = a;
		
	}
};
int phone::ID = 7238465;
class person 
{
public:
	static string coutry;//类内声明，类外初始化。
	string name;
	int* height;
	phone phonename;
	person():name("zjp"),car("bus"),password(123456789) ,phonename("Huawei")//1.构造函数自动调用，仅仅一次 //2.默认值操作
	{                                                 //,phonename("Huawei")约等于phone phonename ="Huawei";隐式转换法
		cout << "构造函数运行了000"<<endl;                                      //phone phonename=phone("Huawei");
	}
	//person(string a,string b,int c) :name(a), car(b), password(c)//第二种形式
	//{
	//	
	//}

	person(int a,int heights)//有参构造函数自动调用，仅仅一次
	{
		height = new int(heights);
		password = a;
		cout << "有参构造函数运行了"<<"int a =" << a<<endl;
	}
	person(const person& a)//拷贝构造函数
	{
		 name = a.name;
		 car = a.car;
		 password = a.password;
		 height = new int(*a.height);//深拷贝，防止拷贝出来的对象的指针只是简简单单的照抄过去，使得两个对象被同时释放时同一个
		                              //指针所指向的空间被释放两次。
		 cout << "拷贝构造函数运行了" << endl;
	}
	~person()//析构函数自动调用，仅仅一次
	{
		
		if (height != NULL)//检查指针 height 是否为 NULL，即是否已经分配了内存。
		{
			delete height; //释放指针 height 所指向的内存空间。
			height = NULL; //将指针 height 置空，即将它指向的地址设置为 NULL。这样做可以避免出现悬空指针
			               //，以确保其他部分不会错误地使用已被释放的内存。
		}
		cout << "析构函数运行了"<<endl;
	}
	void setpassword(int a)
	{
		password = a;
	}
	int readpassword()
	{
		return password;
	}
protected :
	string car;
private:
	int password;//类外不能访问，子类也不可以；
	
};
string person::coutry = "China";//类内声明，类外初始化。//还得写到类后面

    person pptest(person p2)//传进来的person p2是通过拷贝原person来的（调用拷贝函数拷贝的）
	{
		  //cout << p2.readpassword()<<endl;
		person p1=p2;//调用了拷贝构造函数,将p2的所有值原封不动地赋值给p1。
		//p1.setpassword(100);
		return p1;
	}

void loger ()//这个叫全局函数
{
	string cins;
	string sum="   ";
	do
	{
		cin >> cins;
		if (cins == "break")
		{
			break;
		}
		sum += cins;
		system("cls");
		cout << sum;
	} while (1);
}
void test01()
{
	person p;
}
int main() {
	/*
	circle c1;
	c1.r = 99;
	cout << c1.Sout() << endl;
	
	
	string a = "123";
	string b = "456";
	string c = a + b;
	cout << c;
	
	test01();//函数运行完里面的person p就消掉了，然后运行析构函数
	
	person p;//默认构造函数调用
	person p2(8);//括号法
	person p3();//不能这样写，编译器会把这个当做一个函数的声明，person看为返回值类型，p3作为了函数名。不会创建对象。
	
	person p4 = person(28);
	person(88);//匿名对象，当前行执行结束后会立刻回收这个对象。构造与析构会执行
	person(p4);//等价于person p4
	person p5 = 10;//相当于person p5=person(10);隐式转换法
	
	person p1;
	p1.setpassword(1);
	person p44 = pptest(p1);
	cout<<p44.readpassword();
	
	person p3;
	cout << p3.coutry<<endl;//China
	person p99;
	p99.coutry = "USA";
	cout << p99.coutry<<endl;//USA
	cout << p3.coutry << endl;//USA//说明static的数据是所有对象共享的。
	*/
	cout<<person::coutry; //通过类名称访问静态变量。
	phone::IDchages(8372730);//通过类名称访问静态函数。
	cout << phone::ID;
	system("pause");
	return 0;
}
