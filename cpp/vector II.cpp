#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//vector��ͷ�����ݶ�ȡЧ�ʵͣ�����ʮ������ݵ�vector��ͷ������һ��������Ҫ�����ƶ�ʮ�������
//������ָ���Ԫ�ص�ַ��Ϣ�ǹ̶��ģ����vector��Ϊ���˶����´�����һ���ڴ�ռ䣬Ȼ������Ǩ�ƣ�ԭ�е��������ܻ�ָ�����
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
	vector<string> v2(v.begin(), v.begin()+3);//�вι��캯������vector,�����������,����Ǽ�2��һ�б�����ȡ�������һ����ǰ�պ�
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
	//cout << v7.capacity() << endl;//10 ��ʱ��ϵͳ��̬�����С��capacity>=size
	//cout << v7.size() << endl;//10
	//v7.resize(20, "zjp2");//��v7���ݣ�Ĭ��װ�صڶ�������    //���ı�capacity
	//v7.resize(3);//�ض�

	//vector<int> v8(7,7);
	//v8.resize(10, 3);
	//for_each(v8.begin(), v8.end(), printer);
	//cout << endl;
	//v8.pop_back();//ɾ��һ��
	//v8.insert(v8.end(), 100);
	//v8.insert(v8.end(),2, 888);//����888
	//v8.erase(v8.begin());
	//for_each(v8.begin(), v8.end(), printer);
	//cout << endl;
	//v8.erase(v8.begin() + 1, v8.end());//����һ��û�����
	//for_each(v8.begin(), v8.end(), printer);
	//v8.clear();//���
	//cout << endl;

	//cout << v3.at(0)<<endl;
	//cout << v3.back() << endl;//���һ��Ԫ�أ� .begin()�����ǵ�ַ��front��Ԫ��
	//cout << v3.front() << endl;
	//v3[0] = "123";
	//cout << v3.at(0) << endl;

	vector<int> int10000(10000, 888);
	//cout << int10000.capacity() << endl;//10000
	//cout << int10000.size() << endl;//10000
	int10000.resize(3);
	//cout << int10000.capacity() << endl;//10000  //����ͨ��resizeû�а취��10000���ռ�ɾ��3����Ŀռ䣬�ܶ�ռ��˷ѡ�
	//cout << int10000.size() << endl;//3
	vector<int>(int10000).swap(int10000); //ͨ���������캯�������������������������swap������int10000������
	//cout << int10000.capacity() << endl;//3
    //cout << int10000.size() << endl;//3
	
	vector<int> v9;
	//v9.reserve(1000000);//ͨ��Ԥ����С���·������
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
	//cout << --num << endl;//vector���·����ڴ��ַ����

	vector<int> v99;
	v99.push_back(5);
	v99.push_back(7);
	v99.push_back(4);
	v99.push_back(8);
	//vector<int>::iterator ittt=find_if(v99.begin(), v99.end(), bigThenFive());//(�����б� ������ pred����һԪν��)
	//cout << *ittt << endl;//7

		//sort(v99.begin(), v99.end(), compare());//Ĭ�ϴ�С���󣬶�Ԫν���Զ���
	sort(v99.begin(), v99.end(), greater<int>());//Ҳ����
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

//����bool���͵ķº�����Ϊν�� operator����һ��������һԪν�ʣ� 

