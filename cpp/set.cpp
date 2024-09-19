#include<iostream>
#include<set>

using namespace std;
class person
{
public:
	person(string n,int a)
	{
		name = n;
		age = a;
	}
	string name;
	int age;
};
class myCompare//仿函数
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;//set降序排  不写成类的成员函数那么其它的( )也会变成该重载（）
	}
};
//保证对象的常量性：const成员函数可以在常量对象上调用，而非const成员函数不能。这样可以确保在常量对象上调用该函数时，不会对对象的状态进行修改。
//
//提供只读访问：const成员函数只能读取类的成员变量，而不能修改它们。这可以确保在const成员函数中不会意外地修改对象的状态。
//
//支持函数重载：如果一个类有多个同名的成员函数，其中一个是const成员函数，另一个是非const成员函数，那么它们可以根据对象的常量性进行重载。
//这样可以根据对象的常量性选择合适的函数进行调用。
class myCompare2
{
public:
	bool operator()(const person& v1, const person& v2)const
	{
		return v1.age > v2.age;
	}
};
void printer(set<int, myCompare>& s)
{
	for (set<int, myCompare>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << "   ";
	}
	cout << endl;
}

int main()
{
	set<int,myCompare> s;//自动排序，去重复，按照ascII码排序
	s.insert(1);//唯一插数方法
	s.insert(5);
	s.insert(13);
	s.insert(12);
	s.insert(0);
	//printer(s);

	//size empty swap 没有resize
	//erase(pos)迭代器 erase(元素) erase(区间) clear() 

	//cout<<*s.find(12)<<endl;// 如果12存在返回迭代器，不存在返回s.end()
	//cout<<s.count(0);//统计个数

	pair<set<int>::iterator,bool>sett=s.insert(4);//插入时返回迭代器位置，返回是否插入成功
	//cout << *sett.first << endl;
	//cout << sett.second << endl;

	multiset<int> m;//允许重复值的插入，插入完返回迭代器位置

	pair<string, int> p = make_pair("zjp",21);
	pair<string, int> p3("hasduf", 22);
	//cout << p3.first << p3.second << endl;

	set<person,myCompare2>s4;
	person ss("zjp", 221);
	person sss("zjp2", 1);
	person ssss("zjp23", 2);
	s4.insert(ss);
	s4.insert(sss);
	s4.insert(ssss);
	for (set<person, myCompare2>::iterator it = s4.begin(); it != s4.end(); ++it)
	{
		cout << it->name << "   ";
	}
	cout << endl;
}