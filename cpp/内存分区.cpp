#include<iostream>
using namespace std;
static int aastatic = 7;
int quanjubianliang = 9;//��������ı�����ȫ�ֱ���

const int aconstint = 10;//const���ε�ȫ�ֳ���

int a111(int a, double b) {//�ӻ򲻼�constҲ����������������const int& a=10;��const������һ��temp������10���Ϸ���int&a=10;���Ϸ�
	return 0;
}

int a111(string a, double b) {
	return 0;
}

double a111(double a, double b) {
	return 3.1415926;
}

void nothing��2(int) {//����ռλ����
	cout << "nothing? worked"<<"\t";
}

void nothing��(int=99) {//��Ĭ��ֵ�ɲ���
	cout << "nothing? worked" << "\t";
}

int test(int a, int b, int c);//����������ʵ��ֻ����һ������Ĭ��ֵ

int test(int a = 0, int b = 0, int c = 0)//���û�д������������������ǵ�Ĭ��ֵ����int a, int b = 0, int c���ᱨ��
{
	return a + b + c;
}

void test(const int* const a) {//����ֵ����˵int*
	cout << *a;
}

int* qingkong(int ab) {//�ֲ���������ջ��
	 int a=159;
	 int* p = &a;//�ֲ������ں�������ͱ�����������ˣ����Բ�Ҫ�����ǵĵ�ַ��
	return p;
}

int* duiqu() {
	int* p=new int(986);//����
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

	static int a = 10; //�����᷵��һ��ȫ�ֱ��������ã��Ͳ��±�������ɾ������
	                   // ��ȫ������ȫ�����ڳ�����������ݱ�ϵͳ�ͷ�.
	                   //�ڶ��ε��� fanhui() ʱ��static int a = 10; �����ٴ�ִ�С�
					   // ��̬�ֲ������ڵ�һ�ε��ú���ʱ����ʼ��������������������������ڱ�����ֵ��
	return a;
}

int main()
{
	/*
	int jububianliang = 9;//�������ڵı����оֲ�����
	static int aastatic = 7;//��̬��������ȫ������ȫ�����ڳ�����������ݱ�ϵͳ�ͷ�.
	"�ַ�������";//����ȫ��
	const int constint = 99;//�ֲ�����

	//��Ҫ���ؾֲ������ĵ�ַ��ջ������������ɱ������Զ��ͷš�
	
	int* qingkong1 = qingkong(1);
	cout << *qingkong1 << endl; 
	cout << *qingkong1 << endl;//�޷�������������Ѿ�ɾ��
	cout << *qingkong1 << endl;//�޷����
	cout << *qingkong1 << endl;//�޷����
	cout << *qingkong1 << endl;//�޷����
	
	int*p=duiqu();
	int a = *p;
	cout << a;
	cout << a;
	cout << a;
	cout << a;
	cout << a;//�������
	
	for (int i = 0; i < 100; ++i)
	{
		int *p=new int(i);
		cout << *p;
		delete p;//ɾ�ѡ�
	}

	
	int * p= new int[9];//������ʮ������
	p[0] = 100;//��ȡ��д��
	delete[]p;//ɾ������
	
	int a = 8;
	int& b = a;
	int c = 9;
	int& b = c;//int &bֻ���Ե�һ�����������ã������Ժ����ָģ����
	cout << a << endl<<b<<endl<<c;
	
	int a = 1; int b = 1111;
	//int& aa = a; int& bb = b; //�������Բ���д
	swap(a, b);//���ô��ݣ��βλ�����ʵ�Ρ�
	cout << a << endl << b << endl;
	
	int& ref=fanhui();
	cout << ref;
	cout << ref;
	ref = 99;
	fanhui()=9990;//�����������ֵ�����ã�������Ϊ��ֵ
	cout << ref;
	cout << ref;//�������
	
	//int& ref = 10;������
	const int& ref = 9;//�ȼ���int temp=9;int& ref=temp;
	//ref = 9;//ref�����޸�	
	
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
	
	//fanhui() = 9990;//�����������ֵ�����ã�������Ϊ��ֵ
	cout << ref<<endl;//������� 99,����10

	system("pause");
	return 0;
	
}