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
class bools
{
public:
	bool operator()(int b)
	{
		return b > 5;
	}
};
int main()
{

	vector<int> v = { 1,5,8,9,6,4,7,5,6,3,2,1,5,4,6,8,7,9 };
	//vector<int> v2(v.size());
	vector<int> v2(v);
	//copy(v.begin (),v.end(),v2.begin());
	//for_each(v2.begin(), v2.end(), printers());

	//replace(v.begin(), v.end(), 9, 900);
	//for_each(v.begin(), v.end(), printers());

	//replace_if(v.begin(), v.end(), bools(), 5);
	//for_each(v.begin(), v.end(), printers());

	vector<int> v3 = { 2,2,2,2,2,2,2,2,2,2,2};
	swap(v, v3);
	for_each(v.begin(), v.end(), printers());
}