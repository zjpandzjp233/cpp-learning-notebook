#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include <cstdlib>
#include <ctime>
#include <numeric>
using namespace std;
class printers
{
public:
	void operator()(int b)
	{
		cout << b << endl;
	}
};

int main()
{

	vector<int> v = { 1,2,3,4 };
	
	int add=accumulate(v.begin(), v.end(), 0);//�������������ۼ���ʼֵ #include <numeric>
	//cout << add;//10

	fill(v.begin() + 1, v.end(), 9);
	for_each(v.begin(), v.end(), printers());
}