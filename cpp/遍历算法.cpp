#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class printerr
{
public:
	void operator()(int val)
	{
		cout << val << endl;
	}
};
class transformAdd1
{
public:
	int operator()(int val)
	{
		return ++val;
	}
};
int main()
{
	vector<int> v = {1,2,3,6,5,4,7,8,9};
	//for_each(v.begin(), v.end(), printerr());

	vector<int> v2(v.size());
	transform(v.begin(), v.end(), v2.begin(), transformAdd1());
	for_each(v2.begin(), v2.end(), printerr());
}
