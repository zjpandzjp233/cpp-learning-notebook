#include"son.cpp"//先去看son。cpp然后也会去到son。h

template<class T,class B>//函数调用时创建模板函数
void compare(T a, B b)
{
	if (a == b)
	{
		cout << "yyyyyyyyyyyyyy";
	}
	else 
	{
		cout << "nnnnnnn";
	}
}
template<>void compare(person<string, int> a, person<string, int> b)//当调用compare函数时，编译器会根据实际传递的参数类型来确定使用哪个版本的函数。如果传递的参数类型是person<string, int>，那么就会使用这个特化的函数版本。
{
	if (a.name == b.name)
	{
		cout << "yyyyyyyyyyyyyy";
	}
	else
	{
		cout << "nnnnnnn";
	}
}
template<class T >
class person2
{
	T m;
};


int main()
{
	//person<string,int> p1;
	//person<string, int> p2;
	//p1.name = "zjp";
	//p2.name = "zjp";
	//compare(p1, p2);
	son<string,int> s1(1);
	cout << s1.m2 << endl;
	cerr << si.m2 << endl;
	system("pause");
	return 0;

}