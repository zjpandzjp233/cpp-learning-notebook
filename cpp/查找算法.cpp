#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class person
{
public:
	person(string s)
	{
		name = s;
	}
	bool operator==(const person& p2)//定义person的对比方式
	{
		return p2.name == this->name;
	}
	string name;
};
class findIf
{
public://important
	bool operator()( person& p)
	{
		if (p.name == "zjp")
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};
class evenNumber
{
public:
	bool operator()(int i)
	{
		if (i % 2 == 0)
		{
			return true;
		}
		else {
			return false;
		}

	}
};
int main()
{
	vector<int> v;
	for(int i=0;i<=10;++i)
	{
		v.push_back(i);
		if (i == 3)
		{
			v.push_back(3);
		}
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	//cout << *it;

	vector<person> vp;
	person p1("zjp");
	person p2("efa");
	person p3("few");
	person p4("few");
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vector<person>::iterator it2 = find(vp.begin(), vp.end(), p4);
	//cout << (*it2).name;

	vector<person>::iterator it3 = find_if(vp.begin(), vp.end(), findIf());
	//cout << (*it3).name;

	vector<int>::iterator it4 = adjacent_find(v.begin(), v.end());
	if(it4 != v.end())
	{
		//cout << *it4;
	}
	if (it4 == v.end())
	{
		//cout<<"没有找到";
	}

	bool findOrNot = binary_search(v.begin(), v.end(), 5);//只能查元素有序排列的容器,不能倒序
	//cout << findOrNot << endl;

	int counts = count(v.begin(),v.end(),3);//统计自定义数据类型需要重载等号，bool operator==(const person&p)
	//cout << counts << endl;

	int countIf = count_if(v.begin(), v.end(), evenNumber());//自定义数据类型：bool operator()(const person& p)
	cout << countIf << endl;
}