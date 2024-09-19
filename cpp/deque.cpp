#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include <numeric>
using namespace std;
//deque比vector的头部数据的插入、删除更快。 但vector访问元素速度更快
//deque没有capacity函数，大小不限
void Printer(const deque<int>& d)//参数加const防止d被修改
{
	//d[0] = "dfs";
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)//适配const参数的迭代器类型
	{
		cout << *it << endl;
	}
}
int main()
{
	deque<string> d = { "45","456" };
	d[0] = "dfs";
	d.push_front("kadjfisobf");
	d.push_front("kadjfisobf2");
	d.push_front("kadjfisobf3");
	d.push_back("kadjfisobf3");
	d.pop_front();
	//Printer(d);
	cout << endl;
	deque<string> d2(d.begin(), d.end() - 1);
	//Printer(d2);
	cout << endl;
	deque<string> d3(10, "100");
	//Printer(d3);
	cout << endl;
	deque<string> d4;
	d4 = d3;
	//Printer(d4);
	cout << endl;

	deque<int> d5 = { 0,1,2,3,4,5,6,7,8,9 };
	d5.insert(d5.begin(),0);
	//Printer(d5);
	cout << endl;
	d5.insert(d5.end()-1, 2,0);//两个零
	//Printer(d5);
	cout << endl;
	deque<int> d55 = { 0,9,9,9,9,9,9,9,9 };
	deque<int> d6 = { 0,1,2,3,4,5,6,7,8,9 };
	d6.insert(d6.begin() + 1, d55.begin() + 1, d55.end());
	//Printer(d6);
	d55.erase(d55.begin() + 1);
	//Printer(d55);
	d55.erase(d55.begin() + 1,d55.end()-1);
	//d55.clear();
	//Printer(d55);

	deque<int> d66 = { 0,2,1,11,2,3,4,99,5,6,7,8,9 ,0,2,5,4,9,8,2,1,3,6,5,4,8,7,5,2,1,5,9,6,5,8,4,7,5,6,3,0,2,3,2};
	d66.push_back(100);
	sort(d66.begin(), d66.end());
	Printer(d66);

	deque<double> d33;
	d33.push_back(1.3);
	d33.push_back(1.6);
	double sum = accumulate (d33.begin(), d33.end(), 0.0f);//0.0f 避免类型转换
	cout << sum << endl;
}