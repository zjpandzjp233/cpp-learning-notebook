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
class myCompare//�º���
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;//set������  ��д����ĳ�Ա������ô������( )Ҳ���ɸ����أ���
	}
};
//��֤����ĳ����ԣ�const��Ա���������ڳ��������ϵ��ã�����const��Ա�������ܡ���������ȷ���ڳ��������ϵ��øú���ʱ������Զ����״̬�����޸ġ�
//
//�ṩֻ�����ʣ�const��Ա����ֻ�ܶ�ȡ��ĳ�Ա�������������޸����ǡ������ȷ����const��Ա�����в���������޸Ķ����״̬��
//
//֧�ֺ������أ����һ�����ж��ͬ���ĳ�Ա����������һ����const��Ա��������һ���Ƿ�const��Ա��������ô���ǿ��Ը��ݶ���ĳ����Խ������ء�
//�������Ը��ݶ���ĳ�����ѡ����ʵĺ������е��á�
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
	set<int,myCompare> s;//�Զ�����ȥ�ظ�������ascII������
	s.insert(1);//Ψһ��������
	s.insert(5);
	s.insert(13);
	s.insert(12);
	s.insert(0);
	//printer(s);

	//size empty swap û��resize
	//erase(pos)������ erase(Ԫ��) erase(����) clear() 

	//cout<<*s.find(12)<<endl;// ���12���ڷ��ص������������ڷ���s.end()
	//cout<<s.count(0);//ͳ�Ƹ���

	pair<set<int>::iterator,bool>sett=s.insert(4);//����ʱ���ص�����λ�ã������Ƿ����ɹ�
	//cout << *sett.first << endl;
	//cout << sett.second << endl;

	multiset<int> m;//�����ظ�ֵ�Ĳ��룬�����귵�ص�����λ��

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