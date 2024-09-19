#include"head Kid.h"
#include"Kid.h"

HeadKid::HeadKid(int ID ,int deptID,string name)
{
	m_ID = ID;
	m_DeptID=deptID;
	m_Name = name;
}
void HeadKid::ShowInfo()
{
	cout << "职工编号：" << m_ID<<"\t";
	cout << "职工姓名：" << m_Name << "\t";
	cout << "岗位编号:"<<m_DeptID << "\t";
	cout << "岗位:" << GetDeptName() << "\t" << endl;
	bool m_fileIsEmpty = 0;
}
string HeadKid::GetDeptName()
{
	return "班长";
}

LittleKid::LittleKid(int ID, int deptID, string name)
{
	m_ID = ID;
	m_DeptID = deptID;
	m_Name = name;
}
void LittleKid::ShowInfo()
{
	cout << "职工编号：" << m_ID << "\t";
	cout << "职工姓名：" << m_Name << "\t";
	cout << "岗位编号:" << m_DeptID << "\t";
	cout << "岗位:" << GetDeptName() << "\t" << endl;


}
string LittleKid::GetDeptName()
{
	return "小孩";
}