#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2 >
class son : public person2<T1>//��ģ��̳�
{
public:
	son(int a);
	void showm2();

	T2 m2;
};
