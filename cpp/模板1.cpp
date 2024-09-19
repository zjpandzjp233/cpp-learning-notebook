#include<iostream>
using namespace std;
template<typename T>//t必须确定才能运行
void swap2(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void swap2int(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
class person
{
public:
	string name;
};
template<typename T>
void selectionsort(T arry[],int size)//注意传进的参数格式
{
	for (int i = 0; i < size; i++)
	{
		cout << arry[i] <<"******" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		int max = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arry[j] > arry[max])
			{
				max = j;
			}
		}
		if (max != i)
		{
			T temp = arry[i];
			arry[i] = arry[max];
			arry[max] = temp;
		}
	}
	
}
int ADD(int a,int b)
{
	return a + b;
}
int ADD2(int a, int b)
{
	return a + b;
}
template<class T>
int ADD2(T a, T b)
{
	return a + b;
}
template<class T>
int ADD2(T a, T b,T c)
{
	return a + b+c;
}
template<class T>
bool compare=(T a,T b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return flase;
    }
}
int main()
{
	//float a = 3.14;
	//float b = 9.88;
	//swap2(a, b);
	//swap2<float>(a, b);
	//cout << a << ' ' << b << endl;
	//char arr[] ="polkiujmnhytgbvfredcxswqaz";//后面有空格，算size大1
	//int size = sizeof(arr) / sizeof(arr[0])-1;
	//cout << "size:" << size << endl;

	//selectionsort(arr,size);//注意这里的传参类型
	//for(int i=0;i<size;i++)
	//{
	//	cout << arr[i] << endl;
	//}

	//cout << ADD(1, 'a') << endl;//隐式类型转化  a的ASCII编码是97
	//cout << ADD2<int>(1, 'a') << endl;
	//cout << ADD2(1, 'a') << endl;//报错
	//cout<<ADD2<>(1, 2)<<endl;//强制调函数模板
	person p1;
	p1.name = "zjp";
	person p2;
	p2.name = "zjp";
	cout << compare(1, 3);

	system("pause");
	return 0;
}
