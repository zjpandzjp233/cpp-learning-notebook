#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//返回bool类型的仿函数称为谓词 operator接受一个参数叫一元谓词， 
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
		count++;//统计函数被调用次数
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
	sort(v99.begin(), v99.end(),compare() );//默认从小到大，二元谓词自定义
	//for_each(v99.begin(), v99.end(), prints);

	vector<int>::iterator ittt = find_if(v99.begin(), v99.end(), bigThenFive());//(参数列表 迭代器 pred就是一元谓词)
	//cout << *ittt << endl;//7

}