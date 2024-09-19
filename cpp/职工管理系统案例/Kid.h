#pragma once
#include<iostream>
using namespace std;

class Kid//≥ÈœÛ¿‡
{
public:
	virtual void ShowInfo()=0;
	virtual string GetDeptName() = 0; 
	int m_ID=0;
	int m_DeptID=0;
	string m_Name;

};
