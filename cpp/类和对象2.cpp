#include<iostream>
#include<string>
using namespace std;
//ctrl+k+uȡ��ע��
//�ն���ռ�ڴ� 1���������ֶ������ڴ��λ�á�
class person;//                                                      ������Ԫ����      *****����������*******����gays��person������

class gays
{
	public:
	person* p;
	void VisitPrivate();
};

class person
{
	friend ostream& operator<<(ostream& cout, person& p);
	
	friend void gays::VisitPrivate(); // �������û������gays��������޴�����gays::
	friend void ��Ԫ2(person* p);//����������
	friend class girlfriend;
	
	
public:
	static int age;//��̬��Ա������������Ķ����ϣ����������size
	int password ;
	mutable int sex = 1;//����const�������
	
	person():place("bedroom"),height(1.8)
	{
		

	}
	person(int password)
	{
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->password = password;
		
	}
	void func()const//������size���Ͷ����Ա�����ֿ��˴洢//�����const���Ա�֤��Ա�����޸ģ�ʹ��this��ɳ���ָ�볣��
	{//thisָ����ָ�볣����ָ�򲻿��޸�
		if (this == nullptr)//��ֹ��ָ������������Ӵ��뽡׳��
		{
			return;
		}
		cout << "���������ĳ�Ա����������" << endl;//��ָ���޷������к���Ա�����ĺ�������Ϊ��ָ��û�д���������Ա������
		this->sex = 0;
	}
	//person operator+(person& p)  //���������
	//{
	//	person temp;
	//	temp.password = this->password + p.password;
	//	return temp;
	//}
	static void func2()//������size��ͬ��
	{
		
	}

	person& personaddage(person& p)//����return���������������ȥ����һ�е�&��ʹ��41�����20����Ϊ 
	{                             //�������������ʱ�򣬻ᴥ����������������һ����ԭ�����޹صĸ��Ƴ����Ķ���
		this->password += p.password;
		return *this;//thisָ��p22���� *this�Ƕ�����
	}
	person& operator++()//����ǰ�üӼӣ����ش��Σ�������漰һ�����������һ��Ƕ����ڳ�Ա�ĺ���
	{
		++height;
		return *this;
	}
	person& operator++(int)//int��ʾռλ������������������ǰ�úͺ��õ���//���ܷ������ã�����temp�Ǿֲ�����
	{
		//�ȼ�¼��ʱ���
		 person* temp=new person;
		//�����
		height++;
		return *temp;
	}
	
private:
	string place;
	float height;
};
void gays::VisitPrivate()//               ������Ԫ���� *******��������д��person���******��Ϊ��������������Ϊ��Ԫ�����private
{
	p = new person;
	cout << p->place << endl;
}
class girlfriend
{
public:
	person* m_p;
	int age;
	girlfriend();
	void visitbedroom();
	~girlfriend()
	{
		delete m_p;
	}
};
girlfriend::girlfriend()//���⹹��
{
	age = 18;
	m_p = new person;
}
void girlfriend::visitbedroom()//���⺯��
{
	cout<<m_p->place;
}

void ��ָ����ʳ�Ա����()
{
	person* p = nullptr;

	p->func();

	const person p27;//������ֻ���Ե�������,��̬�������޸ľ�̬����
	//p27->age = 100;//���ɸ�
	p27.sex = 0;
	p27.func();//����
}
void ��Ԫ()
{
	person p;
	��Ԫ2(& p);
}
void ��Ԫ2(person* p)
{
	cout << p->place << endl;

}
int person::age = 99;
person operator+(person& a, person& b)//���������
{
	person temp;
	temp.password = a.password + b.password;
	return temp;
}
person operator+( int num, person& p)  //operator+��������//�����������Ҫ
{
	person temp;
	temp.password = p.password + num;
	return temp;
}
//         << �� ���������
//ostream& operator<<(ostream &cout,person&p)//����operator<<(cout,p)��cout<<p //coutȫ��ֻ��һ������������
//{
//	cout << p.password;
//	return cout;//����cout������
//}
ostream& operator<<(ostream& cout, person& p)//Ҳ���ԣ�coutֻ��һ�����֣��ؼ��Ƕ�����<<�������ߵ����ݣ�
{//                                         <<�������ostream���,�ұ���person��ģ�ϵͳ�ͻ���õ��������
	//cout << p.password;
	cout << p.height;//ʵ����Ч��
	return cout;//����cout������,Ϊ����ʽ����
}

int main()
{
	/*
	person p;
	cout << sizeof(p);
	
	person p(888);
	cout << p.password;
	
	person p11(10);
	person p22(10);
	p22.personaddage(p11).personaddage(p11).personaddage(p11);
	cout << p22.password << endl;
	

	��ָ����ʳ�Ա����();
	
	��Ԫ();
	
	girlfriend gg;
	gg.visitbedroom();
	
	gays g;
	g.VisitPrivate();
	
	person a;
	person b;
	a.password = 11111;
	b.password = 22222;
	//person c= a + b;//���ʣ�person c=a.operator+(b);��Ա����   person c=operator+(a,b);ȫ�ֺ���
	person c = 1+a;
	//cout << c.password << endl;
	cout << a << endl;//���û�з���ostream���cout�����ã����ｫ�޷�ʹ��endl�������γ�����ʽ����
	*/
	person p;
	
	cout <<p++<<endl;
	cout << p;
	
	system("pause");
	return 0;
}
//�� C++ �У���������ؿ�����Ϊ��Ա������Ҳ������Ϊȫ�ֺ�����
//���ǣ�++ ��������Լ�����һЩ��������� --�� = ��[]��() ��->�����뱻����Ϊ��Ա������
//������ C++ �����Թ�������ġ�
//���������ⲿ����������Щ�����ʱ��
//�������ᱨ����Ϊ���Ǳ�����Ϊ��ĳ�Ա������ʵ�֡�
//��������һ��ԭ���ǣ���Щ�����ͨ����Ҫ�������˽�г�Ա��
//������Ǳ�����Ϊȫ�ֺ�������ô���ǽ��޷�������Щ˽�г�Ա����������������Ϊ��Ԫ��������