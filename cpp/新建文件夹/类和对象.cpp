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

//����û������вι��캯����C++�����ṩĬ���޲ι��캯�� �����ǻ��ṩĬ�Ͽ�������
//�ȱ������Ķ��������
//����û������˿������캯����C++�������ṩ�������캯��
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
		cout << "���캯���ѵ���001" << endl;
	}
	static void IDchages(int a)//��̬�������ܷ��ʷǾ�̬��Ա
	{
		ID = a;
		
	}
};
int phone::ID = 7238465;
class person 
{
public:
	static string coutry;//���������������ʼ����
	string name;
	int* height;
	phone phonename;
	person():name("zjp"),car("bus"),password(123456789) ,phonename("Huawei")//1.���캯���Զ����ã�����һ�� //2.Ĭ��ֵ����
	{                                                 //,phonename("Huawei")Լ����phone phonename ="Huawei";��ʽת����
		cout << "���캯��������000"<<endl;                                      //phone phonename=phone("Huawei");
	}
	//person(string a,string b,int c) :name(a), car(b), password(c)//�ڶ�����ʽ
	//{
	//	
	//}

	person(int a,int heights)//�вι��캯���Զ����ã�����һ��
	{
		height = new int(heights);
		password = a;
		cout << "�вι��캯��������"<<"int a =" << a<<endl;
	}
	person(const person& a)//�������캯��
	{
		 name = a.name;
		 car = a.car;
		 password = a.password;
		 height = new int(*a.height);//�������ֹ���������Ķ����ָ��ֻ�Ǽ�򵥵����ճ���ȥ��ʹ����������ͬʱ�ͷ�ʱͬһ��
		                              //ָ����ָ��Ŀռ䱻�ͷ����Ρ�
		 cout << "�������캯��������" << endl;
	}
	~person()//���������Զ����ã�����һ��
	{
		
		if (height != NULL)//���ָ�� height �Ƿ�Ϊ NULL�����Ƿ��Ѿ��������ڴ档
		{
			delete height; //�ͷ�ָ�� height ��ָ����ڴ�ռ䡣
			height = NULL; //��ָ�� height �ÿգ�������ָ��ĵ�ַ����Ϊ NULL�����������Ա����������ָ��
			               //����ȷ���������ֲ�������ʹ���ѱ��ͷŵ��ڴ档
		}
		cout << "��������������"<<endl;
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
	int password;//���ⲻ�ܷ��ʣ�����Ҳ�����ԣ�
	
};
string person::coutry = "China";//���������������ʼ����//����д�������

    person pptest(person p2)//��������person p2��ͨ������ԭperson���ģ����ÿ������������ģ�
	{
		  //cout << p2.readpassword()<<endl;
		person p1=p2;//�����˿������캯��,��p2������ֵԭ�ⲻ���ظ�ֵ��p1��
		//p1.setpassword(100);
		return p1;
	}

void loger ()//�����ȫ�ֺ���
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
	
	test01();//���������������person p�������ˣ�Ȼ��������������
	
	person p;//Ĭ�Ϲ��캯������
	person p2(8);//���ŷ�
	person p3();//��������д������������������һ��������������person��Ϊ����ֵ���ͣ�p3��Ϊ�˺����������ᴴ������
	
	person p4 = person(28);
	person(88);//�������󣬵�ǰ��ִ�н���������̻���������󡣹�����������ִ��
	person(p4);//�ȼ���person p4
	person p5 = 10;//�൱��person p5=person(10);��ʽת����
	
	person p1;
	p1.setpassword(1);
	person p44 = pptest(p1);
	cout<<p44.readpassword();
	
	person p3;
	cout << p3.coutry<<endl;//China
	person p99;
	p99.coutry = "USA";
	cout << p99.coutry<<endl;//USA
	cout << p3.coutry << endl;//USA//˵��static�����������ж�����ġ�
	*/
	cout<<person::coutry; //ͨ�������Ʒ��ʾ�̬������
	phone::IDchages(8372730);//ͨ�������Ʒ��ʾ�̬������
	cout << phone::ID;
	system("pause");
	return 0;
}
