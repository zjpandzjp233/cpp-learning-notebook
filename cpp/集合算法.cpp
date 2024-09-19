#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class printer
{
public:

	void operator()(int i)
	{
	

			cout << i << " ";

	
	}
};
int main()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };//必须有序
	vector<int> v2 = {0,6,7,8,9 };//必须有序
	vector<int> v3(v1.size()+v2.size());

	vector<int>::iterator it;
	//vector<int>::iterator it =set_union(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
	printer p;

	//for_each(v3.begin(), it, p);

	//it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	//for_each(v3.begin(), it, p);

	 it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for_each(v3.begin(), it,p);


}