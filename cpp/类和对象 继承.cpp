#include<iostream>
#include<string>
using namespace std;

//����������Ĺ��������˳��
class Coutry
{
public:
	Coutry()
	{
		name = "China";
	}
	string name;
};
class School
{
public:
	School() 
	{
		cout << "School�Ĺ��캯��" << endl;
		age = 50;
	}
	~School() 
	{
		cout << "School����������" << endl;
	}

	//string name;
	static int a;
	int age;
private:
	int ���;
};
int School::a=99;
class Studens :public School,public Coutry//�����̳С�����̳и��࣬������ʱ��Ҳ�������ࡣ������ʱ��л���
{
public:
	Studens()
	{
		cout << "Studens�Ĺ��캯��" << endl;
		age = 18;
	}
	~Studens()
	{
		cout << "Studens����������" << endl;
	}
	int age;
	int ID;
};

void ����������Ĺ��������˳��()
{
	Studens s;
}

class ����
{
public:
	int age;
	����()
	{
		age = 9;
	}
};
class �� :virtual public ����//�漰��ָ��
{};
class �� :virtual public ����
{};
class �ǹ�:public �� ,public �� 
{};

int main()
{
	/*
	Studens student1;
	//student1.name = "jackchen";

	cout << sizeof(student1);//12//private������Ҳ���̳У�ֻ����������������
	
	����������Ĺ��������˳��();

	   // School�Ĺ��캯��
		//Studens�Ĺ��캯��
		//Studens����������
		//School����������

	Studens stu;
	cout << stu.School::age<<endl;//ͬ��������ͬ������������ַ���
	cout << stu.age << endl;//���ʵ�������
	//�������ͺ����Ĺ����ࡣ
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա������
	//Ȼ��Ҫʹ��������������
	
	Studens s;
	cout << Studens::School::a << endl;
	cout << School::a << endl;//���һ��
	*/

	�ǹ� lg;
	lg.age = 9;
	cout << lg.age << endl;//9

	lg.��::age=8;
	cout << lg.age << endl;//8

	lg.��::age = 18;
	cout << lg.age << endl;//18

	lg.��::����::age = 28;
	cout << lg.age << endl;//28

	lg.age = 19;
	cout << lg.��::����::age << endl;//19

	system("pause");
	return 0;
}