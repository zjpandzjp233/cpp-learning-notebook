#include "son.h"
template<class nametype, class agetype = int >//无法自动类型推导，随着更新可以了。    默认参数，类专用
class person
{
public:
	person()
	{
		cout << "typeid(nametype):" << typeid(nametype).name() << endl;
	}
	agetype age;
	nametype name;
};

template<class T1, class T2>
son<T1, T2>::son(int a)//类外实现
{
	m2 = a;
}
template<class T1, class T2>
void son<T1, T2>::showm2()
{
	cout << m2 << endl;
}