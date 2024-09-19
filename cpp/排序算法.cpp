#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include <cstdlib>
#include <ctime>
using namespace std;
class printers
{
public:
	void operator()(int b)
	{
		cout << b << endl;
	}
};
class rules
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
int main()
{
	srand((unsigned int)time(NULL));//使打乱随机

	vector<int> v = { 1,5,8,9,6,4,7,5,6,3,2,1,5,4,6,8,7,9 };
	sort(v.begin(), v.end());//默认从小到大排
	//sort(v.begin(), v.end(),rules());
	//sort(v.begin(), v.end(), greater<int>());
	//for_each(v.begin(), v.end(), printers());

	//random_shuffle(v.begin(), v.end());
	//for_each(v.begin(), v.end(), printers());

	vector<int> v2 = { 1,5,8,3,2,1,5,4,6,8,7,9 };
	sort(v2.begin(), v2.end());//默认从小到大排
	vector<int> out(v.size()+v2.size());
	merge(v.begin(), v.end(), v2.begin(), v2.end(), out.begin());
	//for_each(out.begin(), out.end(), printers());

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), printers());
}