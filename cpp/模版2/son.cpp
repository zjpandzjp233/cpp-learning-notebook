#include "son.h"
template<class nametype, class agetype = int >//�޷��Զ������Ƶ������Ÿ��¿����ˡ�    Ĭ�ϲ�������ר��
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
son<T1, T2>::son(int a)//����ʵ��
{
	m2 = a;
}
template<class T1, class T2>
void son<T1, T2>::showm2()
{
	cout << m2 << endl;
}