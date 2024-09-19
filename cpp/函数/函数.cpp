#include "h.h"
void ptr(int* p1, int* p2)
{
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}
struct student {
	string name;
	int age;
	int score;
}s3;
struct teacher {
	int id;
	string name;
	struct student stu[2];//写法很重要,要有大小。
};
void structarrtest(student a[]) {

	cout << a[1].name;

}
void aaa(int a[])
{
	cout << a[0];
}
void aaaa(int a[])
{
	 a[0] = -123;
}
int main()
{
	
	////int sum = add(7, 3);//sum实参
	////cout << sum;

	////cout<<primenumber(1000);
	//int a = 10;
	//int*p = &a;//简便写法 也就是int*p输出的是p不是*p
	//*p = 1000;
	//cout << sizeof(int*);//int *

	//int* p = NULL;//初始化
	//cout << p;

	/*
	
	int* p;
	p = (int*)0X2315A;
	*p = 5;
	
	
	int a = 2; int b = 8;
	const int* p = &a;//常量指针，指向可以改，指的值不可以改(通过指针手段 如：*p = 8;不可以，如果通过a=2赋值可以改，*p=8的手段也可以)。
	p = &b;//可以
	//*p = 0;这个不可以
	a = 90;//可以
	cout << *p;
	
	int a = 10; int b = 9;
	int* const p = &a;//指针常量，指向不可以改，值可以改。
	*p = 99;//可以
	//p = &b;错
	
	const int* const p = &a;
	
	int arr[4] = { 1,2,3,4 };
	int* ptr=arr;
	cout <<*(ptr+1);
	
	ptr(&a, &b);
	cout << a<<"    " << b;
	

	int* p1=&a; int* p2=&b;
	int** p3 = &p1; **p3 = 8;
	
	int arr[4] = { 1,2,33333,4 };
	int* p = arr;
	cout<<p[2]<<endl; //方便用指针访问数组，如果数组地址传入void函数，可以通过该函数内的此方法改变原数组内的数。
	
	int arr2[2][3] =
	{
		{1, 5, 9},
		{4, 8, 7}
	};

	int* p = &arr2[0][0];
	cout << *(p+1);//5
		*/
	//member s1 = { 19,170,"nick" };//struct可以省略
	/*
	s1.age = 19;
	s1.height = 180;
	s1.name = "jack";
	s3.name = "rabbit";//已经在结构体后面定义了s3
	member memberarr[2] = {
		{11,150,"zjo"},//s0
		{13,150,"fsf"}//s1
	};
	//cout << memberarr[1].age;//数组结构体
	//cout << s3.name;
	member* p = &s1;  ///指针结构体
	cout<<p->name;  //如果不是地址就不能用->应该用 .点
	 

	teacher te;
	//te.id = 789;
	//te.name = "jack";
	//te.stu.name = "jakeson";
	//te.stu.score = 99;

	te.stu[0].name = "nice";
	te.stu[1].name = "done";
	te.stu[0].score = 600;
	cout << te.stu[0].name<<" " << te.stu[1].name;

	_______函数传结构体时，如果将包含成千上万人的结构体一起传过去会特别消耗性能，如果传的是结构体的指针，就会节省很多内存。________

	
	student stu[3];
	stu[1].name = "succeed";
	structarrtest(stu);//函数中的结构体数组传递方法
	
	int aa[3];//而这里aa是地址。
	aa[0] = 8808;
	//int* p = aa;
	//cout <<* p;//8808
	aaa(aa);//系统会自动转换
	
	string str00 = "LEFT DEAD";
	str00[8] = 'B';
	str00 += '2';
	cout << str00;//LEFT DEAB2
	
int returN;
cin >> returN;
if (returN == 9) {
	return 0;//return后该函数会立即退出，也就是不做后面的任何操作了。
	           另外，在 void 函数中使用 return 的主要目的是提前结束函数的执行并返回到调用该函数的地方
}
  

    system("cls");//clean screen清屏
	

int a[9];
a[0] = 123456;
aaaa(a);//传进去的是地址，会改变这边的值。
cout << a[0];
*/

	system("pause");
	return 0;

}

