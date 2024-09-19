#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class person
{
	public:
		person(int age)
		{
			this->age = age;
		}
		int age;
};
void myprint(int s)
{
	cout << s << endl;
}
void myprint2(person* p)
{
	cout << p->age <<"new" << endl;
}
void test()
{
	person zjx(16);
	person zjx2(17);
	person zjx3(18);
	person zjx4(19);
	vector<person*> v3;
	v3.push_back(&zjx);
	v3.push_back(&zjx2);
	v3.push_back(&zjx3);
	v3.push_back(&zjx4);
	for_each(v3.begin(), v3.end(), myprint2);
}
int main()
{
	vector<string> v;
	v.push_back("hello ");
	v.push_back("world ");
	vector<string>::iterator itBegin = v.begin();// v.begin() 起始迭代器 指向容器里第一个元素
	vector<string>::iterator itEnd = v.end(); //指向最后一个元素的下一个元素

	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	
	//while (itEnd!=itBegin)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//for (vector<string>::iterator it=v.begin(); it != itEnd; it++)
	//{
	//	cout << *it<< endl;
	//}
	//for_each(numbers.begin(), numbers.end(),myprint);

	person zjx(16);
	person zjx2(17);
	person zjx3(18);
	person zjx4(19);
	vector<person> v3;
	v3.push_back(zjx);
	v3.push_back(zjx2);
	v3.push_back(zjx3);
	v3.push_back(zjx4);
	//for (vector<person>::iterator it2 = v3.begin(); it2 != v3.end(); ++it2)
	//{
	//	cout << (*it2).age << endl;
	//	cout << it2->age << endl;// same
	//}

	//test();

	vector<vector<int>> v5;
	vector<int> v66 = { 1,2,3,4,5,6,7,8 };
	vector<int> v77 = { 1,2,3,4,5,6,7 };
	v5.push_back(v66);
	v5.push_back(v77);
	/*for (vector<vector<int>>::iterator it5=v5.begin(); it5!=v5.end() ; it5++)
	{
		for (vector<int>::iterator it6 = it5->begin(); it6 != it5->end(); it6++)
		{
			cout << *it6 << endl;
		}
	}*/

	cout<<v66[2];
}