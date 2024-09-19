#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2 >
class son : public person2<T1>//ÀàÄ£°å¼Ì³Ð
{
public:
	son(int a);
	void showm2();

	T2 m2;
};
