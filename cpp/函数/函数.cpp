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
	struct student stu[2];//д������Ҫ,Ҫ�д�С��
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
	
	////int sum = add(7, 3);//sumʵ��
	////cout << sum;

	////cout<<primenumber(1000);
	//int a = 10;
	//int*p = &a;//���д�� Ҳ����int*p�������p����*p
	//*p = 1000;
	//cout << sizeof(int*);//int *

	//int* p = NULL;//��ʼ��
	//cout << p;

	/*
	
	int* p;
	p = (int*)0X2315A;
	*p = 5;
	
	
	int a = 2; int b = 8;
	const int* p = &a;//����ָ�룬ָ����Ըģ�ָ��ֵ�����Ը�(ͨ��ָ���ֶ� �磺*p = 8;�����ԣ����ͨ��a=2��ֵ���Ըģ�*p=8���ֶ�Ҳ����)��
	p = &b;//����
	//*p = 0;���������
	a = 90;//����
	cout << *p;
	
	int a = 10; int b = 9;
	int* const p = &a;//ָ�볣����ָ�򲻿��Ըģ�ֵ���Ըġ�
	*p = 99;//����
	//p = &b;��
	
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
	cout<<p[2]<<endl; //������ָ��������飬��������ַ����void����������ͨ���ú����ڵĴ˷����ı�ԭ�����ڵ�����
	
	int arr2[2][3] =
	{
		{1, 5, 9},
		{4, 8, 7}
	};

	int* p = &arr2[0][0];
	cout << *(p+1);//5
		*/
	//member s1 = { 19,170,"nick" };//struct����ʡ��
	/*
	s1.age = 19;
	s1.height = 180;
	s1.name = "jack";
	s3.name = "rabbit";//�Ѿ��ڽṹ����涨����s3
	member memberarr[2] = {
		{11,150,"zjo"},//s0
		{13,150,"fsf"}//s1
	};
	//cout << memberarr[1].age;//����ṹ��
	//cout << s3.name;
	member* p = &s1;  ///ָ��ṹ��
	cout<<p->name;  //������ǵ�ַ�Ͳ�����->Ӧ���� .��
	 

	teacher te;
	//te.id = 789;
	//te.name = "jack";
	//te.stu.name = "jakeson";
	//te.stu.score = 99;

	te.stu[0].name = "nice";
	te.stu[1].name = "done";
	te.stu[0].score = 600;
	cout << te.stu[0].name<<" " << te.stu[1].name;

	_______�������ṹ��ʱ�������������ǧ�����˵Ľṹ��һ�𴫹�ȥ���ر��������ܣ���������ǽṹ���ָ�룬�ͻ��ʡ�ܶ��ڴ档________

	
	student stu[3];
	stu[1].name = "succeed";
	structarrtest(stu);//�����еĽṹ�����鴫�ݷ���
	
	int aa[3];//������aa�ǵ�ַ��
	aa[0] = 8808;
	//int* p = aa;
	//cout <<* p;//8808
	aaa(aa);//ϵͳ���Զ�ת��
	
	string str00 = "LEFT DEAD";
	str00[8] = 'B';
	str00 += '2';
	cout << str00;//LEFT DEAB2
	
int returN;
cin >> returN;
if (returN == 9) {
	return 0;//return��ú����������˳���Ҳ���ǲ���������κβ����ˡ�
	           ���⣬�� void ������ʹ�� return ����ҪĿ������ǰ����������ִ�в����ص����øú����ĵط�
}
  

    system("cls");//clean screen����
	

int a[9];
a[0] = 123456;
aaaa(a);//����ȥ���ǵ�ַ����ı���ߵ�ֵ��
cout << a[0];
*/

	system("pause");
	return 0;

}

