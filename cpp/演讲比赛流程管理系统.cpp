#include<iostream>
#include<fstream>
using namespace std;
#define zjp "zhongjiping"
#define ze "2899828783@qq.com"
class father
{
public:
	int greater(int a,int b)
	{
		if (a == b)
		{
			return 0;
		}
		if(a>b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
};
class son:public father
{
public:
	int lower(int a, int b)
	{
		if (a == b)
		{
			return 0;
		}
		if (a < b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
};
class 新知识
{
public:
	int newK(father*& f)
	{
		return f->greater(3, 9);
	}
};
int main()
{
	ofstream of;
	of.open("file.csv", ios::out | ios::app);//总体来说，ios::app 主要用于在文件末尾追加内容，而 ios::ate 允许在文件中的任意位置进行读写操作，但默认读写位置被设置到文件末尾。
	of << 54654854<<',';
	of << 546554 << ',';
	of << 654854 << ',';
	of << endl;
	of << 54654561854 << ',';
	of << 546542454 << ',';
	of << 654851111111114 << ',';
	of << 654851111111114 << ',';
	of.close();


	//cout << ze;

	father* f=new father();
	son* s = (son*)f;//父类指针转子类 调用子类的接口时用
	//cout << s->greater(3, 6) << endl;

	father* f2 = new father();
	新知识 x;
	//cout<<x.newK(f2);


	ofstream o;
	o.open("1.txt", ios::out);
	//o << "dfsfdsfsf 5484848484";
	o.close();
	ifstream i4;
	i4.open("1.txt", ios::in);
	
	string s7="";
	i4 >> s7;
	// cout << i4.good();0
	cout << s7 << endl;
	cerr << s7;
	if (i4.get() == EOF)//get可读取单个字符，利用EOF可判断文件是否为空
	{
		cout << "empty";
	}
	//也可以用：file.good() 的含义是：如果文件流 file 不处于正常状态（即不是打开的、已到达文件末尾或发生了错误），则该表达式的结果为 flase


	system("pause");
	return 0;
	
}