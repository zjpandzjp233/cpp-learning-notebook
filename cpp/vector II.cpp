#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//vector对头部数据读取效率低，比如十万个数据的vector，头部插入一个数据需要往后移动十万个数据
//迭代器指向的元素地址信息是固定的，如果vector因为满了而重新创建了一块内存空间，然后数据迁移，原有迭代器可能会指向错误
void printer(int v)
{
	cout << "v:" << v << endl;
}
void printer2(bool v)
{
	cout << "v:" << v << endl;
}
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
	bool operator()(int i1, int i2)const
	{
		return i1 > i2;
	}
};
int main()
{
	vector<string> v = { "zjp","zjp2","zjp3" };
	vector<string> v2(v.begin(), v.begin()+3);//有参构造函数创建vector,输入的是区间,如果是加2下一行报错，读取不到最后一个。前闭后开
	//cout << v2[2] << endl;

	vector<string> v6;
	v6.assign(v.begin(), v.begin() + 3);
	//cout << v2[2] << endl;

	vector<string> v3(10, "zjp");
	//cout << *(v3.begin()+9) << endl;

	vector<string> v4(v3);
	//cout << *(v4.begin() + 9) << endl;

	vector<string> v5 = v4;
	//cout << *(v5.begin() + 9) << endl;

	vector<string> v7;
	v7.assign(10, "zjp");
	//cout << v7[9];

	//cout << v7.empty() << endl;
	//cout << v7.capacity() << endl;//10 有时候系统动态分配大小，capacity>=size
	//cout << v7.size() << endl;//10
	//v7.resize(20, "zjp2");//给v7扩容，默认装载第二个参数    //不改变capacity
	//v7.resize(3);//截短

	//vector<int> v8(7,7);
	//v8.resize(10, 3);
	//for_each(v8.begin(), v8.end(), printer);
	//cout << endl;
	//v8.pop_back();//删除一个
	//v8.insert(v8.end(), 100);
	//v8.insert(v8.end(),2, 888);//两个888
	//v8.erase(v8.begin());
	//for_each(v8.begin(), v8.end(), printer);
	//cout << endl;
	//v8.erase(v8.begin() + 1, v8.end());//留了一个没有清空
	//for_each(v8.begin(), v8.end(), printer);
	//v8.clear();//清空
	//cout << endl;

	//cout << v3.at(0)<<endl;
	//cout << v3.back() << endl;//最后一个元素， .begin()给的是地址，front给元素
	//cout << v3.front() << endl;
	//v3[0] = "123";
	//cout << v3.at(0) << endl;

	vector<int> int10000(10000, 888);
	//cout << int10000.capacity() << endl;//10000
	//cout << int10000.size() << endl;//10000
	int10000.resize(3);
	//cout << int10000.capacity() << endl;//10000  //单独通过resize没有办法给10000个空间删成3个大的空间，很多空间浪费。
	//cout << int10000.size() << endl;//3
	vector<int>(int10000).swap(int10000); //通过拷贝构造函数生成匿名对象，匿名对象调用swap函数，int10000作参数
	//cout << int10000.capacity() << endl;//3
    //cout << int10000.size() << endl;//3
	
	vector<int> v9;
	//v9.reserve(1000000);//通过预定减小重新分配次数
	int* p=nullptr;
	int num = 0;
	for (int i = 0; i < 1000000; ++i)
	{
		v9.push_back(i);
		if (p != &v9[0])
		{
			p = &v9[0];
			++num;
		}
	}
	//cout << --num << endl;//vector重新分配内存地址次数

	vector<int> v99;
	v99.push_back(5);
	v99.push_back(7);
	v99.push_back(4);
	v99.push_back(8);
	//vector<int>::iterator ittt=find_if(v99.begin(), v99.end(), bigThenFive());//(参数列表 迭代器 pred就是一元谓词)
	//cout << *ittt << endl;//7

		//sort(v99.begin(), v99.end(), compare());//默认从小到大，二元谓词自定义
	sort(v99.begin(), v99.end(), greater<int>());//也可以
	//for_each(v99.begin(), v99.end(), printer);

	vector<bool> b1;
	b1.push_back(true);
	b1.push_back(true);
	b1.push_back(true);
	b1.push_back(false);
	vector<bool> b22;
	b22.resize(b1.size());
	transform(b1.begin(), b1.end(), b22.begin(), logical_not<bool>());
	cout << b22[3];//1
	
}

//返回bool类型的仿函数称为谓词 operator接受一个参数叫一元谓词， 

