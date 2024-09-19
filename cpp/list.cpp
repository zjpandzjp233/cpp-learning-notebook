#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
class person
{
public:
	person(int a,int b)
	{
		age = a;
		score = b;
	}
	int age;
	int score;
};
void printer(const list<int>& L)
{
	for (list<int>::const_iterator it =L.begin(); it != L.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}
bool compareR(int a,int b)
{
	return  a > b;
}
bool compareP(person& a, person& b)
{
	if (a.age == b.age)
	{
		return a.score > b.score;//������ͬ�Ļ��������ߵ���ǰ��
	}
	return  a.age > b.age;
}
int main()
{
	list<int> li10(20,10);
	list<int> li100(20, 100);
	li10.swap(li100);//resize()��size������empty����Ҳ���е�
	//printer(li10);
	//printer(li100);
	//100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100
	//10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10

	list<int> li3 = { 20,10,8,5,4,1,2,3,6,9,8,1,5,6,1,5,1,2,5,4,1,7,4,1,5,1,5,1,6,1,5,8,1 };
	li3.remove(1);//�Ƴ�����1Ԫ��
	//printer(li3);
	
	//cout << li3[3];��C++�У�std::list��һ��˫����������������֧��ʹ��[]�������ֱ�ӷ���Ԫ�ء�������Ϊ��������Ծ���������Ԫ�ز��������洢�ģ�����ͨ��ָ��������һ��ġ�
	//cout << li3.front() <<"  "<< li3.back() << endl;

	list<int>::iterator it = li3.begin();
	it = ++it;//+1+3������
	//cout << *it << endl;

	list<int> li4 = { 20,10,8,5,4,1,2,3,6,9,8,1,5,6,1,5,1,2,5,4,1,7,4,1,5,1,5,1,6,1,5,8,1 };
	li4.reverse();
	//printer(li4);
	li4.sort();
	li4.sort(compareR);//ͨ������������
	//printer(li4);

	person p1(2,1);
	person p2(21,2);
	person p22(21, 0);
	person p3(22,5);
	person p4(42,1);
	person p5(27,4);
	person p6(21,11);
	list<person> it5;
	it5.push_front(p1);
	it5.push_front(p2);
	it5.push_front(p22);
	it5.push_front(p3);
	it5.push_front(p4);
	it5.push_front(p5);
	it5.push_front(p6);
	it5.sort(compareP);//�Զ��������������
	for (list<person>::iterator it = it5.begin(); it != it5.end(); ++it)
	{
		cout << it->age<<"   ";
		cout << it->score << endl;
	}
}