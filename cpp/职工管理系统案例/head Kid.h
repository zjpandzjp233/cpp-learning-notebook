#pragma once
#include<iostream>
using namespace std;
#include "Kid.h"
class HeadKid:public Kid
{
public:
	HeadKid(int ID, int deptID, string name);
	 void ShowInfo() ;
	 string GetDeptName() ;
};
class LittleKid :public Kid
{
public:
	LittleKid(int ID, int deptID, string name);
	void ShowInfo();
	string GetDeptName();
};