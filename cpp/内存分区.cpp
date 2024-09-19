#include<iostream>
using namespace std;
static int aastatic = 7;
int quanjubianliang = 9;//函数体外的变量叫全局变量

const int aconstint = 10;//const修饰的全局常量

int a111(int a, double b) {//加或不加const也可以做差别的条件。const int& a=10;（const会让有一个temp来接受10）合法，int&a=10;不合法
	return 0;
}

int a111(string a, double b) {
	return 0;
}

double a111(double a, double b) {
	return 3.1415926;
}

void nothing？2(int) {//函数占位参数
	cout << "nothing? worked"<<"\t";
}

void nothing？(int=99) {//有默认值可不传
	cout << "nothing? worked" << "\t";
}

int test(int a, int b, int c);//函数声明和实现只能有一个定义默认值

int test(int a = 0, int b = 0, int c = 0)//如果没有传参数过来，就用我们的默认值。（int a, int b = 0, int c）会报错
{
	return a + b + c;
}

void test(const int* const a) {//输入值可以说int*
	cout << *a;
}

int* qingkong(int ab) {//局部变量，在栈区
	 int a=159;
	 int* p = &a;//局部变量在函数用完就被编译器清空了，所以不要返他们的地址。
	return p;
}

int* duiqu() {
	int* p=new int(986);//堆区
	return p;
}

void swap(int& ax, int& bx)
{
	int temp = ax;
	ax= bx;
	bx = temp;
}

int giveme5() {
	return 5;
}

int& fanhui()
{

	static int a = 10; //这样会返回一个全局变量的引用，就不怕被编译器删变量了
	                   // 在全局区。全局区在程序结束后数据被系统释放.
	                   //第二次调用 fanhui() 时，static int a = 10; 不会再次执行。
					   // 静态局部变量在第一次调用函数时被初始化，并在整个程序的生命周期内保持其值。
	return a;
}

int main()
{
	/*
	int jububianliang = 9;//函数体内的变量叫局部变量
	static int aastatic = 7;//静态变量，在全局区。全局区在程序结束后数据被系统释放.
	"字符串常量";//属于全局
	const int constint = 99;//局部常量

	//不要返回局部变量的地址，栈区分配的数据由编译器自动释放。
	
	int* qingkong1 = qingkong(1);
	cout << *qingkong1 << endl; 
	cout << *qingkong1 << endl;//无法输出，编译器已经删除
	cout << *qingkong1 << endl;//无法输出
	cout << *qingkong1 << endl;//无法输出
	cout << *qingkong1 << endl;//无法输出
	
	int*p=duiqu();
	int a = *p;
	cout << a;
	cout << a;
	cout << a;
	cout << a;
	cout << a;//可以输出
	
	for (int i = 0; i < 100; ++i)
	{
		int *p=new int(i);
		cout << *p;
		delete p;//删堆。
	}

	
	int * p= new int[9];//数组有十个数据
	p[0] = 100;//读取与写入
	delete[]p;//删除方法
	
	int a = 8;
	int& b = a;
	int c = 9;
	int& b = c;//int &b只可以当一个变量的引用，不可以后面又改，错的
	cout << a << endl<<b<<endl<<c;
	
	int a = 1; int b = 1111;
	//int& aa = a; int& bb = b; //这条可以不用写
	swap(a, b);//引用传递，形参会修饰实参。
	cout << a << endl << b << endl;
	
	int& ref=fanhui();
	cout << ref;
	cout << ref;
	ref = 99;
	fanhui()=9990;//如果函数返回值是引用，可以作为左值
	cout << ref;
	cout << ref;//可以输出
	
	//int& ref = 10;不可用
	const int& ref = 9;//等价于int temp=9;int& ref=temp;
	//ref = 9;//ref不可修改	
	
	int a = 9;
	int* p = &a;
	test(p);
	
	const int& a = 10;
	cout <<a;
	*/
	int& ref = fanhui();
	cout << ref<<endl;
	ref = 99;
	fanhui();
	
	//fanhui() = 9990;//如果函数返回值是引用，可以作为左值
	cout << ref<<endl;//可以输出 99,不是10

	system("pause");
	return 0;
	
}