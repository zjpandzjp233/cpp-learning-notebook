#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//����bool���͵ķº�����Ϊν�� operator����һ��������һԪν�ʣ� 
class c
{
public:
	int count;
	c()
	{
		count = 0;
	}
	void operator()(string s)
	{
		cout << s<<endl;
		count++;//ͳ�ƺ��������ô���
	}
};
class bigThenFive
{
public:
	bool operator()(int i1)const
	{
		return i1 > 5;
	}
};
class compare
{
public:
	bool operator()(int i1,int i2)const
	{
		return i1 > i2;
	}
};
void prints(int i)
{
	if(i>5)
	{
		cout << i << endl;
	}
}
int main()
{
	c c;
	c("zjp");

	vector<int> v99;
	v99.push_back(5);
	v99.push_back(7);
	v99.push_back(4);
	v99.push_back(8);
	sort(v99.begin(), v99.end(),compare() );//Ĭ�ϴ�С���󣬶�Ԫν���Զ���
	//for_each(v99.begin(), v99.end(), prints);

	vector<int>::iterator ittt = find_if(v99.begin(), v99.end(), bigThenFive());//(�����б� ������ pred����һԪν��)
	//cout << *ittt << endl;//7

}