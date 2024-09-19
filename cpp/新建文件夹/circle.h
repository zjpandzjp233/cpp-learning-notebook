#pragma once
#include<iostream>
using namespace std;

const double PI = 3.1415926;

class circle {
	// 访问权限 ，属性 ，行为
private:
	int r = 0;
public:
	double Sout()const;

	void setr(int a);


};
