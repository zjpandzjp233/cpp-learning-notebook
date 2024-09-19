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
		return a.score > b.score;//年龄相同的话按分数高的排前面
	}
	return  a.age > b.age;
}
int main()
{
	list<int> li10(20,10);
	list<int> li100(20, 100);
	li10.swap(li100);//resize()、size（）、empty（）也是有的
	//printer(li10);
	//printer(li100);
	//100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100
	//10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10

	list<int> li3 = { 20,10,8,5,4,1,2,3,6,9,8,1,5,6,1,5,1,2,5,4,1,7,4,1,5,1,5,1,6,1,5,8,1 };
	li3.remove(1);//移除所有1元素
	//printer(li3);
	
	//cout << li3[3];在C++中，std::list是一个双向链表容器，它不支持使用[]运算符来直接访问元素。这是因为链表的特性决定了它的元素不是连续存储的，而是通过指针链接在一起的。
	//cout << li3.front() <<"  "<< li3.back() << endl;

	list<int>::iterator it = li3.begin();
	it = ++it;//+1+3不允许
	//cout << *it << endl;

	list<int> li4 = { 20,10,8,5,4,1,2,3,6,9,8,1,5,6,1,5,1,2,5,4,1,7,4,1,5,1,5,1,6,1,5,8,1 };
	li4.reverse();
	//printer(li4);
	li4.sort();
	li4.sort(compareR);//通过反函数降序
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
	it5.sort(compareP);//自定义类型排序规则
	for (list<person>::iterator it = it5.begin(); it != it5.end(); ++it)
	{
		cout << it->age<<"   ";
		cout << it->score << endl;
	}
}