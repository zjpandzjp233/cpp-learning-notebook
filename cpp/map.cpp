#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class compare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

void print(map<int,string,compare> m)
{
	for (map<int, string,compare>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << (*it).first; cout << "  ";
		cout << (*it).second;
		cout << endl;
	}
}
int main()
{
	//不允许重复key值，multimap允许
	map<int, string,compare> m; //map<int, string> m;
	m.insert(pair<int, string>(1, "zjp1"));
	m.insert(pair<int, string>(3, "zjp3"));
	m.insert(pair<int, string>(2, "zjp2"));//不存在隐式转换
	m.insert(make_pair(0,"zjp0"));
	m[9] = "zjp9";//当访问[key]值不存在时，map会自动创建对应key值为0的项
	//cout << m[3]<<endl;
	//print(m);
	//拷贝构造和=赋值都可以
	// 
	//size（） empty（） swap（） 都可以
	//insert(elem) clear() erase(pos迭代器)返回下一个元素的迭代器   erase(begin,end)返回下一个元素的迭代器    erase(key)

    //find(key),查找key是否存在，存在返回迭代器，不存在返回。end（）
	//count（key） 统计key的个数

	for (int i = 0; i >= 0 && i < 99; i += 1, i *= i)//多条件
	{
		//cout << i << endl;
	}


	//multimap <double, int, greater<double>>groupscore;//一个multimap，但是是以降序排序
	// 定义一个 multimap，按照得分降序排列
	std::multimap<double, int, std::greater<int>> groupscore;

	// 添加一些用户得分信息
	groupscore.insert({ 98.5, 101 });
	groupscore.insert({ 92.0, 102 });
	groupscore.insert({ 98.5, 103 });
	groupscore.insert({ 87.5, 104 });

	// 遍历 multimap，显示分组信息
	for (const auto& pair : groupscore)//遍历方法
	{
		std::cout << "得分: " << pair.first << ", 用户ID: " << pair.second << std::endl;
	}



}